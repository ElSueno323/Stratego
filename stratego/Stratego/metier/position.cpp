#include "position.h"

Position::Position(int x, int y):x_{x}, y_{y}{


}

Position::Position():x_{0}, y_{0}{
}



bool Position::operator ==(const Position & p){
    if(p.x_ == x_ && p.y_ == y_){
        return true;
    }

    return false;
}
int Position::getX() const{
    return x_;
}
int Position::getY() const{
    return y_;
}

int abs(int i){
    if(i < 0){
        return -i;
    }
    return i;
}


bool Position::neighboor(const Position & o) const{

    if(abs(x_ - o.getX()) == 1 && abs(y_ - o.getY()) == 0){
        return true;
    }


    if(abs(x_ - o.getX()) == 0 && abs(y_ - o.getY()) == 1){
        return true;
    }
    return false;
}


