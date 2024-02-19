#ifndef BOARD_H
#define BOARD_H

#include <array>
#include "case.h"
#include "position.h"
#include <vector>
#include <list>
#include <map>
/**
 * \brief The Board class
 */

class Board
{
private:
    Case cases_[10][10];
    std::vector<Entity> p1l_;
    std::vector<Entity> p2l_;
    bool end;

public :
    /**
     * \brief Board
     */
    Board();

    /**
     * \brief move the entity
     * \param from the position of the entity
     * \param to the new position of the entity
     * \return
     */
    char move(const Position & from, const Position & to,const int & currentPlayer);
    /**
     * \brief getP1l get hte vector of entity for the player 1.
     * \return the vector of entity.
     */
    std::vector<Entity> getP1l() const;
    /**
     * \brief getP2l get hte vector of entity for the player 2.
     * \return the vector of entity.
     */
    std::vector<Entity> getP2l() const;
    /**
     * \brief getArCases get a cases of the board in a position.
     * \return a case.
     */
    Case getArCases(Position pos) const;

    /**
     * \brief getCase get the case at pos.
     * \param pos the position to get the case.
     * \return the case.
     */
    const Case * getCase(const Position & pos) const;

    /**
     * \brief destroy destroy the entity in some position and if is a flag the game is end.
     * \param pos a Position in the board.
     *
     */
    void destroy(const Position & pos, const int & cur);

    /**
     * \brief isEnd check if is the end of the game
     * \return true if it is the end
     */
    bool isEnd()const;
    /**
     * \brief emptyBoard check if the board is empty.
     * \return true if the board is empty.
     */
    bool emptyBoard()const;
    /**
     * \brief put put a entity on the board and check if the position is free.
     * \param en a Entity .
     * \param pos a Position of the board.
     * \return 0 if ok, 2 if the case is not available.
     */
    char put(Entity * en, const Position & pos);

    /**
     * \brief giveEntityPlayer give entity who is in the player vector
     * if there is no entity because already in the game return a nullptr .
     * \param ower the player of the entity.
     * \param r a ROLE of the entity.
     * \return a entity who is in the vector of player.
     */
    Entity * giveEntityPlayer(const int & ower,ROLE & r);

    /**
     * \brief spawnEnd check if the STATE spawn is end and change the STATE in TURN if true.
     * \param player the player who check if he finish the spawn STATE.
     * \return a boolean , true if finish is spawn end.
     */
    bool spawnEnd(int player) const;


    bool Drunk(Position frm,Position tor);

private:
    /**
     * \brief checkDash check if the dash with the position is correct.
     * \param from the inital Position.
     * \param to the edn Position.
     * \return a booleans true if the dash is correctly do.
     */
    bool checkDash(Position from,Position to)const;
};



#endif // BOARD_H
