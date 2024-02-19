#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "position.h"
#include "STATE.h"
#include <string>
#include "observable.h"
#include <list>
/**
 * \brief The Game class
 */
class Game: Observable{
private:
    int currentPlayer_;
    Board * board;
    STATE state;
    std::list<Observer *> lo;
public:

    Game();
    /**
     * \brief isEnd check the end of the game.
     * \return return true if one flag is catched.
     */
    bool isEnd()const;

    /**
     * \brief turnPlayer change the turn of the current player. Only when the STATE is TURN or SPAWN.
     */
    void turnPlayer();

    /**
     * \brief getCurrentPlayer return the current player.
     * \return return the current player.
     */
    int getCurrentPlayer()const;
    /**
     * \brief getState give the State of the game.
     * \return a STATE,
     */
    STATE getState()const;
    /**
     * \brief start the game only when the STATE is MENU. And change the STATE in SPAWN.
     */
    void start();

    /**
     * \brief move use the move of board who move entity on a position to a other. Only if the STATE is SPAWN.
     * \param from a Position of the entity who want to move.
     * \param to a Position where the entity arrive at.
     * \return
     */
    char moveTo(Position from, Position to);
    /**
     * \brief spawnEnd use the spawnEnd of board, and if the spawn of all player is end ,change the STATE in TURN.
     * \return a boolean, true if the STATE as Spawn.
     */
    bool spawnEnd(int player);


    /**
     * \brief reset the game
     */
    void reset();
    /**
     * \brief createFileMap
     */
    void createFileMap();
    /**
     * \brief put a entity in a certain position (only place to the board)
     * \param r the role of the entity
     * \param pos the position to place the entity
     * \return 0 if the entity in put at position, 1 if the entity is already on board
     */
    char put(std::string r,const Position pos);
    /**
     * \brief getCase use getCase of board , give the case at the given position.
     * \param pos a Position of the board to put.
     * \return a case of the board.
     */
    const Case * getCase(Position pos) const;

    void registerObserver(Observer * o) override
    {
        lo.push_back(o);
    }

    void removeObserver(Observer * o) override
    {
        lo.remove(o);
    }

    void notifyAllObserver(std::string m) override
    {
        for(Observer * o: lo)
        {
            o->update(m);
        }
    }

    ~Game();


};

#endif // GAME_H
