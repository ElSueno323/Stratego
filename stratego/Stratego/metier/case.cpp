#include "case.h"


Case::Case(): en_{nullptr},hole_{false},available_{true}{
}

void Case::setEntity(Entity * e){
    if(e != nullptr){
        e->setInGame(true);
        available_=false;
    }
    else
    {
        available_=true;
    }
    en_ = e;
}

Entity * Case::getEntity() const{
    return en_;
}
bool Case::isHole() const{
    return hole_;
}
void Case ::setHole(){
    hole_ = true;
}
bool Case::isAvailable() const{
    return available_ && !hole_;
}

bool Case::isDispo() const{
    return available_;
}

Case::~Case(){

}

