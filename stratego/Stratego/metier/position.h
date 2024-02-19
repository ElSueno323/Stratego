#ifndef POSITION_H
#define POSITION_H


/**
 * \brief The Position class
 */
class Position{
private:
    int x_;
    int y_;
public:
    /**
     * \brief main constructor.
     * \param x the x position.
     * \param y the y position.
     */
    explicit Position(int x, int y);
    /**
     * \brief Position set to (0;0).
     */
    Position();
    /**
     * \brief compare two position.
     * \param p the other postion to compare.
     * \return true if the both position are in same place.
     */
    bool operator ==(const Position & p);
    /**
     * \brief getX give the value of x.
     * \return a constante integer.
     */
    int getX()const;
    /**
     * \brief getY give the value of y.
     * \return a constante integer.
     */
    int getY()const;
    /**
     * \brief neighboor check if the select position is around it.
     * \param o a position which will be verified.
     * \return a boolean, true if the position is around it.
     */
    bool neighboor(const Position & o)const;
};



#endif // POSITION_H
