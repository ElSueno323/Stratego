#include "board.h"
#include "entity.h"
#include <vector>
#include <algorithm>
#define LENGTH 10

Board::Board(): end{false}{


    cases_[2][4].setHole();
    cases_[3][4].setHole();

    cases_[2][5].setHole();
    cases_[3][5].setHole();

    cases_[6][4].setHole();
    cases_[7][4].setHole();

    cases_[6][5].setHole();
    cases_[7][5].setHole();

    for(int i=0;i<13;i++){
        switch(i){
        case 10:
            p1l_.push_back(Entity{MARSHAL,1});
            p2l_.push_back(Entity{MARSHAL, 2});
            break;
        case 1:
            p1l_.push_back(Entity{GENERAL,1});
            p2l_.push_back(Entity{GENERAL,2});
            break;
        case 2:
            for(int i = 0; i < 2; i++){
                p1l_.push_back(Entity{COLONEL,1});
                p2l_.push_back(Entity{COLONEL,2});
            }
            break;
        case 3:
            for(int i = 0; i < 3; i++){
                p1l_.push_back(Entity{MAJOR,1});
                p2l_.push_back(Entity{MAJOR,2});
            }
            break;
        case 4:
            for(int i = 0; i < 4; i++){
                p1l_.push_back(Entity{COMMANDER,1});
                p2l_.push_back(Entity{COMMANDER,2});
            }
            break;
        case 5:
            for(int i = 0; i < 4; i++){
                p1l_.push_back(Entity{LIEUTENANT,1});
                p2l_.push_back(Entity{LIEUTENANT,2});
            }
            break;
        case 6:
            for(int i = 0; i < 4; i++){
                p1l_.push_back(Entity{SERGEANT,1});
                p2l_.push_back(Entity{SERGEANT,2});
            }
            break;
        case 7:
            for(int i = 0; i < 5; i++){
                p1l_.push_back(Entity{DEMINER,1});
                p2l_.push_back(Entity{DEMINER,2});
            }
            break;
        case 8:
            for(int i = 0; i < 7; i++){//i<8
                p1l_.push_back(Entity{SCOUT,1});
                p2l_.push_back(Entity{SCOUT,2});//scout-1=+1drunked
            }
            break;
        case 9:
            p1l_.push_back(Entity{SPY,1});
            p2l_.push_back(Entity{SPY,2});
            break;
        case 0:
            p1l_.push_back(Entity{DRAPEAU,1});
            p2l_.push_back(Entity{DRAPEAU,2});

            break;
        case 11:
            for(int i = 0; i < 6; i++){
                p1l_.push_back(Entity{BOMBE,1});
                p2l_.push_back(Entity{BOMBE,2});
            }
            break;
        case 12:
            p1l_.push_back(Entity{DRUNKED_SCOUT,1});
            p2l_.push_back(Entity{DRUNKED_SCOUT,2});//drunked
        }
    }


}

char Board::put(Entity * en, const Position & pos){


    if(cases_[pos.getX()][pos.getY()].isAvailable()){
        cases_[pos.getX()][pos.getY()].setEntity(en);
        return 0;
    }

    return 2;

}

char Board::move(const Position & from, const Position & to,const int & curPlay){


    Entity * fr = cases_[from.getX()] [from.getY()].getEntity();
    Entity * t = cases_[to.getX()] [to.getY()].getEntity();

    if(fr == nullptr){
        throw std::invalid_argument("On ne peut bouger dans un trou ,Veuillez rejouer");
    }
    if(cases_[to.getX()] [to.getY()].isHole()){
        throw std::invalid_argument("On ne peut bouger dans un trou ,Veuillez rejouer");
    }

    if(fr->getRole()  == BOMBE || fr->getRole() == DRAPEAU){
        throw std::invalid_argument("On ne peut pas deplacer les bombes et le drapeau,Veuillez rejouer");
    }
    if(fr->getOwner()!=curPlay){
        throw std::invalid_argument("Deplacement de troupes adverses impossible ,Veuillez rejouer");
    }
    if(!from.neighboor(to) ){
        if(fr->getRole()==SCOUT){
            if(!checkDash(from,to)){
                throw std::invalid_argument("Deplacement interdit,Veuillez rejouer");
            }
        }
        else if(fr->getRole()==DRUNKED_SCOUT){
            if(!Drunk(from,to)){
                throw std::invalid_argument("pas DrunkedScout");//-----------dunked scout
            }
        }
        else{
            throw std::invalid_argument("On ne peut bouger d'une seule case a la fois ,Veuillez rejouer");
        }

    }
    if(t == nullptr) {
        cases_[to.getX()] [to.getY()].setEntity(fr);
        cases_[from.getX()] [from.getY()].setEntity(nullptr);
        return 0;
    } else {
        if(fr->getOwner() != t->getOwner()){

            if(fr->getRole()==DEMINER&&t->getRole()==BOMBE){

                cases_[from.getX()][from.getY()].setEntity(nullptr);
                cases_[to.getX()][to.getY()].setEntity(nullptr);
                return 0;
            }

            if(fr->attack(t) == 1){

                if(curPlay == 1){
                    destroy(to, 2);
                }else{
                    destroy(to,1);
                }
                cases_[to.getX()] [to.getY()].setEntity(fr);
                cases_[from.getX()][from.getY()].setEntity(nullptr);

            }else if(fr->attack(t) == 0){

                destroy(from,curPlay);
                if(curPlay==1){
                    destroy(to,2);
                }else{
                    destroy(to,1);
                }
                cases_[from.getX()] [from.getY()].setEntity(nullptr);
                cases_[to.getX()] [to.getY()].setEntity(nullptr);
            }else if(fr->attack(t) == -1){

                destroy(from,curPlay);
                cases_[from.getX()] [from.getY()].setEntity(nullptr);
            }
            return 0;
        }else{
            throw std::invalid_argument("On ne peut pas attaquer ses troupes ,Veuillez rejouer");
        }
    }
}

bool Board::Drunk(Position frm,Position tor){//---------------Drunked
    if(frm.getX()==tor.getX()){
        if(frm.getY()==tor.getY()){
            return false;
        }
        if(frm.getY()+1>tor.getY()||frm.getY()-1<tor.getY()){
            return false;
        }
    }
    if(frm.getX()!=tor.getX()){
        if(frm.getY()+1==tor.getY()&&frm.getX()+1==tor.getX()){

            return true;
        }
        if(frm.getY()-1==tor.getY()&&frm.getX()-1==tor.getX()){
            return true;
        }
    }
    return false;
}





std::vector<Entity> Board::getP1l() const{
    return p1l_;
}

std::vector<Entity> Board::getP2l() const{
    return p2l_;
}

const Case * Board::getCase(const Position & pos) const{
    return &cases_[pos.getX()] [pos.getY()];
}

void Board::destroy(const Position &pos, const int & cur){

    if(cur == 1){
        auto it = std::find(p1l_.begin(), p1l_.end(), *cases_[pos.getX()] [pos.getY()].getEntity());

        if(it->getRole() == DRAPEAU){
            end = true;
        }
        it->setInGame(false);
    }
    if(cur == 2){
        auto it = std::find(p2l_.begin(), p2l_.end(), *cases_[pos.getX()] [pos.getY()].getEntity());

        if(it->getRole() == DRAPEAU){
            end = true;
        }
        it->setInGame(false);
    }
}

bool Board::isEnd() const{
    return end;
}

bool Board::emptyBoard() const{
    return !(p1l_.empty() && p2l_.empty());
}






bool Board::checkDash(Position from, Position to)const {
    int max;
    int min;

    if(from.getX()!=to.getX()&&from.getY()!=to.getY()){
        return false;
    }
    if(from.getX() != to.getX()){
        if(from.getX() < to.getX()){

            max=to.getX();
            min=from.getX()+1;
        } else {

            min = to.getX()+1;
            max = from.getX();
        }

        for(int x =min;x<max;x++){
            if(!cases_[x][from.getY()].isAvailable()){
                return false;
            }
        }
    }else {
        if(from.getY() < to.getY()) {

            max = to.getY();
            min = from.getY()+1;
        }else{

            min = to.getY()+1;
            max = from.getY();
        }
        for(int y=min;y<max;y++){
            if(!cases_[from.getX()][y].isAvailable()){
                return false;
            }
        }
    }
    return true;
}

Entity * Board::giveEntityPlayer(const int & owner,ROLE & r){
    if(owner==1){
        auto  itt {p1l_.begin()};
        while(itt < p1l_.end()){
            if(itt->getRole() ==r && !itt->isInGame()){
                itt->setInGame(true);
                return &(*itt);
            }
            itt++;
        }
    }
    else if(owner == 2){
        auto  itt {p2l_.begin()};
        while(itt < p2l_.end()){
            if(itt->getRole() ==r && !itt->isInGame()){
                itt->setInGame(true);
                return &(*itt);
            }
            itt++;
        }
    }
    return nullptr;
}

bool Board::spawnEnd(int player) const{
    auto iter{p1l_.begin()};
    auto end{p1l_.end()};
    if (player==2){
        iter={p2l_.begin()};
        end={p2l_.end()};
    }

    while(iter<end){

        if(!(iter->isInGame())){
            return false;
        }
        iter++;
    }
    return true;
}

Case Board::getArCases(Position pos) const{
    return cases_[pos.getX()][pos.getY()];

}

