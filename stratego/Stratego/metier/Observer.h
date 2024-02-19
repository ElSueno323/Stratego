#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
class Observer{

public:

    virtual void update(std::string m) = 0;

    ~Observer(){}
};

#endif // OBSERVER_H
