#include "pawn.h"
#include <QIcon>
#include "ROLE.h"
Pawn::Pawn(int x, int y, const Case * c,  QWidget * parent) : QToolButton(parent), c{c}, x_ {x}, y_{y}
{

    setStyleSheet("border:none;");
    QString s = ":/ground/grassL";


    QString team = "B";
    if(c != nullptr){
        if(!c->isDispo()){
            if(c->getEntity()->getOwner() == 2){
                team = "R";
            }

            switch(c->getEntity()->getRole()) {

            case DRAPEAU:
                s = ":/pawn/"+team+"_flag";
                break;
            case SPY:
                s = ":/pawn/"+team+"_spy";
                break;
            case BOMBE:
                s = ":/pawn/"+team+"_bomb";
                break;
            case MARSHAL:
                s = ":/pawn/"+team+"_10";
                break;
            case GENERAL:
                s = ":/pawn/"+team+"_9";
                break;
            case COLONEL:
                s = ":/pawn/"+team+"_8";
                break;
            case MAJOR:
                s = ":/pawn/"+team+"_7";
                break;
            case COMMANDER:
                s = ":/pawn/"+team+"_6";
                break;
            case LIEUTENANT:
                s = ":/pawn/"+team+"_5";
                break;
            case SERGEANT:
                s = ":/pawn/"+team+"_4";
                break;
            case DEMINER:
                s = ":/pawn/"+team+"_3";
                break;
            case SCOUT:
                s = ":/pawn/"+team+"_2";
                break;
            case DRUNKED_SCOUT:
                break;
            case NONE:
                break;

            }
        }

    }else{
        s = ":/ground/sea";
    }


    icon = new QIcon(QPixmap(s));
    setIcon(*icon);
    setIconSize(QSize(50, 50));

}

void Pawn::updateIcon(int current){
    QString s = ":/ground/grassL";


    QString team = "B";
    if(c != nullptr){
        if(!c->isDispo()){
            if(c->getEntity()->getOwner() == 2) {

                team = "R";
            }
            switch(c->getEntity()->getRole()){
            case DRAPEAU:
                s = ":/pawn/"+team+"_flag";
                break;
            case SPY:
                s = ":/pawn/"+team+"_spy";
                break;
            case BOMBE:
                s = ":/pawn/"+team+"_bomb";
                break;
            case MARSHAL:
                s = ":/pawn/"+team+"_10";
                break;
            case GENERAL:
                s = ":/pawn/"+team+"_9";
                break;
            case COLONEL:
                s = ":/pawn/"+team+"_8";
                break;
            case MAJOR:
                s = ":/pawn/"+team+"_7";
                break;
            case COMMANDER:
                s = ":/pawn/"+team+"_6";
                break;
            case LIEUTENANT:
                s = ":/pawn/"+team+"_5";
                break;
            case SERGEANT:
                s = ":/pawn/"+team+"_4";
                break;
            case DEMINER:
                s = ":/pawn/"+team+"_3";
                break;
            case SCOUT:
                s = ":/pawn/"+team+"_2";
                break;
            case NONE:
                break;
            }

            if(current != c->getEntity()->getOwner()){
                s = ":/pawn/"+team+"_back";
            }
        }

    }else{
        s = ":/ground/sea";
    }

    setIcon(QIcon(s));
}
void Pawn::changeIcon(){
    QString s = ":/ground/grassD";
    setIcon(QIcon(s));
}
Pawn::~Pawn(){

}
