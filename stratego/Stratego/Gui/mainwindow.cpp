#include "mainwindow.h"

#include <QGridLayout>
#include <QWidget>
#include <QPushButton>
MainWindow::MainWindow(Game * g, QWidget *parent)
    : QMainWindow(parent),
      v {new View{g, this}}
{


    setWindowTitle("Stratego");
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);

    setCentralWidget(v);



}

MainWindow::~MainWindow()
{
    delete v;
}

