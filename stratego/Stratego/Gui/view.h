#ifndef VIEW_H
#define VIEW_H


#include "game.h"
#include "observer.h"
#include "pawn.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QHBoxLayout>

class View: public QWidget, public Observer
{
    Q_OBJECT
public:
    View(Game * game, QWidget * parent = nullptr);
    ~View();


public slots:
    /**
     * \brief moveToPut when the state of game is spawn , can put entity on the board.
     *                  When the state of game is turn ,can move entity on the board.
     */
    void moveToPut();
    /**
     * \brief spawnSelect select a role for put in game.
     */
    void spawnSelect();
    /**
     * \brief beginStart start the game for spawn.
     */
    void beginStart();
    /**
     * \brief beginLoad read a file for create the board for the game.
     */
    void beginLoad();


private:
    /**
     * \brief initView initialize the all window of the game.
     */
    void initView();
    /**
     * \brief initRightSide initiate the right side of the view.
     */
    void initRightSide();
    /**
     * \brief update of the observer
     * \param m
     */
    void update(std::string m) override;
    /**
     * \brief display create the view of the board.
     */
    void display();
    /**
     * \brief createFileMap read the file for create the board .
     */
    void createFileMap();

    /**
     * \brief g the model of the game.
     */
    Game * game;
    /**
     * \brief window the window of the application.
     */
    QVBoxLayout * window;
    /**
     * \brief hbox contains the board and the lsit of pawn
     */
    QHBoxLayout * hbox;
    /**
     * \brief grid the board of the game
     */
    QGridLayout * grid;
    /**
     * \brief rightSide the right side of the window with the button with spawn selection.
     */
    QGridLayout * rightSide;

    /**
     * \brief config contains buttons to load and start a game
     */
    QHBoxLayout * config;
    /**
     * \brief data_list the list of pawn in the selected spawn.
     */
    QList <Pawn * > data_list;
    /**
     * \brief state give a info of the game.
     */
    QLabel * state;
    /**
     * \brief buttons
     */
    QHBoxLayout * buttons;
    /**
     * \brief start the button for begin the game on the spawn state.
     */
    QPushButton * start;
    /**
     * \brief load the button for load a file for start the game.
     */
    QPushButton * load;
    /**
     * \brief roleSpawn give the role sleected for the spawn.
     */
    QString * roleSpawn;
    /**
     * \brief from the position of the begin move for the entity.
     */
    Position * from;
    /**
     * \brief to the position of the end move for the entity.
     */
    Position * to;

    /**
     * \brief take check if a role is already take.
     */
    bool take;
    bool loaded;
};

#endif // VIEW_H
