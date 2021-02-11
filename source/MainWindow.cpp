#include "MainWindow.h"
#include "InputArea.h"

MainWindow::MainWindow()
{
    InputArea* ia = new InputArea();

    setCentralWidget(ia);
}