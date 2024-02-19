#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "view.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Game * g, QWidget *parent = nullptr);
    ~MainWindow();

private:
    View * v;
};
#endif // MAINWINDOW_H
