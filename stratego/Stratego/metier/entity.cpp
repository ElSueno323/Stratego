#include "entity.h"
#include <iostream>


Entity::Entity(ROLE role, int owner):role_{role}, owner_{owner} ,inGame_{false}{

    initEntity();
}

void Entity::initEntity(){
    distance_ = 1;


    switch(role_){
    case MARSHAL:
        symbole_ = "10";
        attack_ = 10;

        break;
    case GENERAL:
        symbole_ = " 9";
        attack_ = 9;
        break;
    case COLONEL:
        symbole_ = " 8";
        attack_ = 8;
        break;
    case MAJOR:
        symbole_ = " 7";
        attack_ = 7;
        break;
    case COMMANDER:
        symbole_ = " 6";
        attack_ = 6;
        break;
    case LIEUTENANT:
        symbole_ = " 5";
        attack_ = 5;
        break;
    case SERGEANT:
        symbole_ = " 4";
        attack_ = 4;
        break;
    case DEMINER:
        symbole_ = " 3";
        attack_ = 3;
        break;
    case SCOUT:
        symbole_ = " 2";
        attack_ = 2;
        distance_ = 10;
        break;
    case SPY:
        symbole_ = " 1";
        attack_ = 1;
        break;
    case DRAPEAU:
        symbole_ = " D";
        attack_ = 0;

        break;
    case BOMBE:
        symbole_ = " B";
        attack_ = 11;
        break;
    case DRUNKED_SCOUT:
        symbole_=" W";
        attack_=2;
        break; //dunked scout
    case NONE:
        break;
    }
}

int Entity::getAttack() const{
    return attack_;
}

ROLE Entity::getRole() const{
    return role_;
}

int Entity::getOwner() const{
    return owner_;
}

bool Entity::isInGame()const{
    return inGame_;
}

void Entity::setInGame(bool chg){
    inGame_=chg;
}
std::string Entity::getSymbol()  const{
    return symbole_;
}

int Entity::attack (Entity * o) const{
    if(o->owner_ == owner_){
        return 2;
    }
    if(o->attack_ > this->attack_){
        return -1;
    }else if(o->attack_ < this->attack_){
        return 1;
    }
    else if(o->attack_ == this->attack_){
            return 0;
        }
    return 0;
}

bool Entity::operator == (const Entity & o){

    return this == &o;

}

