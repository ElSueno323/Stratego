#ifndef PAWN_H
#define PAWN_H

#include <QToolButton>
#include <QWidget>
#include <QObject>
#include "Case.h"
#include "ROLE.h"


class Pawn: public QToolButton
{
public:
    Pawn(int x, int y, const Case * c, QWidget * parent = nullptr);
    /**
     * \brief getX give the value of x.
     * \return  a constante integer.
     */
    int getX()const{
        return x_;
    }
    /**
     * \brief getY give the value of y.
     * \return a constante integer.
     */
    int getY()const{
        return y_;
    }
    /**
     * \brief changeIcon change the icon of the pawn.
     */
    void changeIcon();
    /**
     * \brief updateIcon when has a change.
     */
    void updateIcon(int);
    ~Pawn();
private:
    QIcon * icon;
    const Case * c;
    int x_;
    int y_;

};

#endif // PAWN_H
