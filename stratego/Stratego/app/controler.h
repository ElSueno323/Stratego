#ifndef CONTROLER_H
#define CONTROLER_H

#include "game.h"
#include "view.h"

class Controler
{
    Game * g_;
    View * v_;
public:
    Controler(Game * g, View * v);
    /**
     * \brief init initializes the game and do the spawn phase
     */
    void init();
    /**
     * \brief loop the main loop of the gamen , move a entity,check if the game is end and change player
     */
    void loop();

private:
    /**
     * \brief createFileMap read the file to use it as a default board of the game.
     */
    void createFileMap();
};

#endif // CONTROLER_H
