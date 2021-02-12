#ifndef MAINWINDOW
#define MAINWINDOW

#include <QMainWindow>

#include "InputArea.h"

class MainWindow : public QMainWindow
{
public:
    MainWindow();

private:
    InputArea* ia;

protected:
     void closeEvent(QCloseEvent *event);
};

#endif