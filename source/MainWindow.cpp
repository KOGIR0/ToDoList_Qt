#include "MainWindow.h"

#include <QFile>
#include <vector>
#include <QTextStream>
#include <QString>

MainWindow::MainWindow()
{
    ia = new InputArea();

    setCentralWidget(ia);
}

void MainWindow::closeEvent(QCloseEvent *event) {
    
    QFile file("ToDoList.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    std::vector<QString> tasks = ia->getTasks();
    QTextStream out(&file);
    for(QString t : tasks)
    {
        out << t << '\n';
    }
}