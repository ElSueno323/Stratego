#include "controller.h"

Controller::Controller(Game * g, View * v): g {g}, v{v}
{
    g->registerObserver(v);
}


