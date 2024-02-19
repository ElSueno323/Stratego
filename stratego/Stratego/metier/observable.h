#ifndef OBSERVABLE_H
#define OBSERVABLE_H


#include "observer.h"
#include <string>
#include <list>

class Observable
{
public:
    virtual void registerObserver(Observer * o) = 0;
    virtual void removeObserver(Observer * o) = 0;
    virtual void notifyAllObserver(std::string m) = 0;

    ~Observable(){ }
private:
    std::list<Observer *> lo;

};

#endif // OBSERVABLE_H
