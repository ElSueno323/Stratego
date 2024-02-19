#ifndef ENTITY_H
#define ENTITY_H


#include "ROLE.h"
#include <string>
/**
 * \brief The Entity class
 */
class Entity{


private:
    ROLE role_;
    int owner_;
    int distance_;
    int attack_;
    bool inGame_;
    std::string symbole_;
    /**
     * \brief initEntity initialise attributs depending to the role
     */
    void initEntity();

public:
    /**
     * \brief Entity constructor.
     * \param role the role of the entity.
     * \param owner the owner of this entity.
     */
    explicit Entity(ROLE role, int owner);

    /**
     * \brief getAttack return the attack.
     * \return the attack.
     */
    int getAttack() const;
    /**
     * \brief getRole return the role.
     * \return return the role.
     */
    ROLE getRole() const;
    /**
     * \brief getOwner return the owner of the entity.
     * \return the owner.
     */
    int getOwner() const;

    /**
     * \brief attack compare and said who wins the attack.
     * \param o a entity.
     */
    int attack(Entity * o)const;

    /**
     * \brief getSymbol give the symbole of the entity.
     * \return a string.
     */
    std::string getSymbol() const;
    /**
     * \brief isInGame check if the entity is in the board.
     * \return a boolean, true if the entity is in game.
     */
    bool isInGame()const;
    /**
     * \brief setInGame change if the entity is in the game.
     * \param chg a boolean,true if the entity is in game.
     */
    void setInGame(bool chg);
    /**
     * \brief operator == change the operator fonction and check if two entity are the same.
     * \param o a other entity.
     * \return true if they are same.
     */
    bool operator == (const Entity & o);

};

#endif // ENTITY_H
