#ifndef VIEW_H
#define VIEW_H

#include <string>
#include <game.h>

class View
{
private:
    Game * g_;

public:
    View(Game * g);

    /**
     * \brief displayTitle print the title of the game.
     */
    void displayTitle();
    /**
     * \brief displayState print the state fo the game.
     */
    void displayState();
    /**
     * \brief displayBoard print the board of the game.
     */
    void displayBoard();
    /**
     * \brief displayWinner print the player who win the game.
     */
    void displayWinner();
    /**
     * \brief displayErreur print the error who is in the parameter.
     * \param m a error in string.
     */
    void displayErreur(std::string m);
    /**
     * \brief displayTurn print the player who is the turn.
     */
    void displayTurn();
    /**
     * \brief displayMessage print the message who is in the parameter.
     */
    void displayMessage(std::string);
    /**
     * \brief clean clean the console.
     */
    void clean();
    /**
     * \brief askRole ask to the player a role in string and return it on ROLE.
     * \return a string.
     */
    std::string askRole();
    /**
     * \brief askPosition ask to the player a position in string and return it on Position.
     * \return a Position.
     */
    Position askPosition();
    /**
     * \brief askChoice ask to the player if he wants begin with default map or a custom.
     * \return a Boolean,true if is O.
     */
    bool askChoice();

//private:---------------------------------------------------
    int askNumber(std::string message);
};

#endif // VIEW_H
