#include "controler.h"
#include "mapreader.h"
#include "position.h"

using namespace std;

Controler::Controler(Game * g, View * v):  g_{g}, v_{v}
{}

void Controler::init(){

    g_->start();
    while(!(g_->spawnEnd(1)&&g_->spawnEnd(2))){
        //v_->displayState();
        v_->displayBoard();
        v_->displayTurn();
        try {
            Position p = v_->askPosition();
            while(!g_->getCase(p)->isAvailable()||
                   (g_->getCurrentPlayer()==1 && p.getY()>3)||(g_->getCurrentPlayer()==2 && p.getY()<6)){

                if((g_->getCurrentPlayer()==1 && p.getY()>3)||(g_->getCurrentPlayer()==2 && p.getY()<6)){
                    v_->displayErreur("Spawn ennemi");
                }
                else{
                    v_->displayErreur("Case deja prise");
                }
                p = v_->askPosition();
            }
            char po = g_->put(v_->askRole(), p);
            if(po != 0){
                if(po == 1){
                    v_->displayErreur("PLus  ");//---------------
                }
                else if( po == 2){
                    v_->displayErreur("Case deja prise");
                }
            }
        }  catch (const std::exception& x) {
            v_->displayErreur(x.what());
        }
        if(g_->getCurrentPlayer()==1 && g_->spawnEnd(1)){
            v_->displayMessage("Changement de tour");
            //g_->turnPlayer();--------
        }
    }
    g_->turnPlayer();
}

void Controler::loop(){
    v_->displayTitle();

    Position from;
    Position to;
    if(v_->askChoice()){
        g_->start();
        createFileMap();
    }
    else {
        init();
    }
    while(!g_->isEnd()){
        try{
            v_->displayTurn();
            v_->displayBoard();
            v_->displayMessage("Départ");
            from = v_->askPosition();
            v_->displayMessage("Arrivé");
            to = v_->askPosition();
            g_->moveTo(from, to);
            g_->turnPlayer();
            v_->clean();
        } catch(const std::exception& x) {
            v_->displayErreur(x.what());
        }
    }
    v_->displayWinner();

}
void Controler::createFileMap(){
    g_->createFileMap();
}
