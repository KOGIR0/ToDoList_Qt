#include "Task.h"
#include "TasksList.h"

#include <QFile>
#include <QTextStream>

TasksList::TasksList(QWidget* parent) : QWidget(parent)
{
    layout = new QVBoxLayout();

    QFile file("ToDoList.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            layout->addWidget(new Task(line));
        }
    }

    setLayout(layout);
}

std::vector<QString> TasksList::getTasks()
{
    std::vector<QString> tasks;
    for(int i = 0; i < layout->count(); i++)
    {
        Task* t = dynamic_cast<Task*>(layout->itemAt(i)->widget());
        tasks.push_back(t->getText());
    }
    return tasks;
}

void TasksList::addTask(const QString& text)
{
    layout->addWidget(new Task(text));
}