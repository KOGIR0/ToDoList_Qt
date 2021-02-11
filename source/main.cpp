#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QScrollArea>
#include <QLineEdit>
#include <QSizePolicy>
#include <QGridLayout>
#include <QString>

#include <vector>
#include <string>

#include "Task.h"
#include "TasksList.h"
#include "InputArea.h"
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.resize(200, 200);
    window.setWindowTitle("ToDoList");
    window.show();

    return app.exec();
}