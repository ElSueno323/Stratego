#include "mainwindow.h"

#include <QApplication>
#include "game.h"
#include "controller.h"

using namespace std;

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    Game * g {new Game{}};
    View * v = new View(g);
    Controller * c = new Controller(g, v);

    return a.exec();
}
