#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "game.h"
#include "view.h"
class Controller
{
public:
    /**
     * \brief Controller connect the view and the game with observer observet.
     * \param g the model of the game.
     * \param v the view of the game.
     */
    Controller(Game * g, View * v);

private:
    Game * g;
    View * v;

};

#endif // CONTROLLER_H
