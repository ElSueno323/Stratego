#include "game.h"
#include "mapreader.h"
#include <string>
Game::Game(): currentPlayer_{1}, board{new Board{}},state{MENU}
{


}

bool Game::isEnd() const{
    return board->isEnd();
}

void Game::turnPlayer(){
    if(state!=TURN && state!=SPAWN){
        throw std::invalid_argument("Le STATE du jeux n'est pas => TURN");}
    if(currentPlayer_ == 1){
        currentPlayer_ = 2;
    }else{
        currentPlayer_ = 1;
    }
}

int Game::getCurrentPlayer()const{
    return currentPlayer_;
}

void Game::start(){
    if(state!=MENU){
        throw std::invalid_argument("Le STATE du jeux n'est pas => MENU");
    }
    state=SPAWN;
    notifyAllObserver("Started");
}

char Game::moveTo(Position from, Position to){
    if(state!=TURN){
        throw std::invalid_argument("Le STATE du jeux n'est pas => TURN");
    }
    try{
        board->move(from, to, currentPlayer_);
        if(board->isEnd()){
            notifyAllObserver("End");
        }else{
            notifyAllObserver("Moved");
        }
    }catch(std::exception& e){
        notifyAllObserver(e.what());
    }
    return 0;
}

char Game::put(const std::string r,const Position pos){
    if(state!=SPAWN){
        throw std::invalid_argument("Le STATE du jeux n'est pas => SPAWN");
    }
    if((getCurrentPlayer()==1 && pos.getY()>3)||(getCurrentPlayer()==2 && pos.getY()<6)){
        throw std::invalid_argument("Mauvais coté,spawn ennemi");
    }

    ROLE role;
    if(r=="10"){role=MARSHAL;};
    if(r=="9"){role=GENERAL;};
    if(r=="8"){role=COLONEL;};
    if(r=="7"){role=MAJOR;};
    if(r=="6"){role=COMMANDER;};
    if(r=="5"){role=LIEUTENANT;};
    if(r=="4"){role=SERGEANT;};
    if(r=="3"){role=DEMINER;};
    if(r=="2"){role=SCOUT;};
    if(r=="1"){role=SPY;};
    if(r=="D"){role=DRAPEAU;};
    if(r=="B"){role=BOMBE;};
    if(r=="W"){role=DRUNKED_SCOUT;};
    Entity * e = board->giveEntityPlayer(getCurrentPlayer(),role);
    if(e == nullptr){
        throw std::invalid_argument("Plus de pion de ce type");
    }

    char x =board->put(e,pos);
    if((currentPlayer_==1&&spawnEnd(1))||(currentPlayer_==2&&spawnEnd(2))){
        turnPlayer();
    }
    notifyAllObserver("Put");
    return x;
}

void Game::createFileMap(){
    mapReader read{};
    while(!(spawnEnd(1)&&spawnEnd(2))){
        for(int p = 1; p <= 2; p++){
            read.init(p);
            for (int x=0;x<10 ;x++ ) {
                for (int y=0;y<4 ;y++ ) {
                    put(read.getValueOf(x,y),Position(x,y + ((p-1) * 6)));
                }
            }
        }
    }
}

void Game::reset(){
    delete board;
    currentPlayer_ = {1};
    board = {new Board{}};
    state = {MENU};
    notifyAllObserver("Reset");
}

bool Game::spawnEnd(int player) {
    if(board->spawnEnd(1) && board->spawnEnd(2)){
        state=TURN;
    }
    return board->spawnEnd(player);
}
const Case * Game::getCase(Position pos) const{

    return board->getCase(pos);
}

STATE Game::getState()const{
    return state;
}


Game::~Game()  {
    delete board;
}
