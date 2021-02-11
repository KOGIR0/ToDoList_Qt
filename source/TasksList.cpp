#include "Task.h"
#include "TasksList.h"


TasksList::TasksList(QWidget* parent) : QWidget(parent)
{
    layout = new QVBoxLayout();
    setLayout(layout);
}

void TasksList::addTask(const QString& text)
{
    layout->addWidget(new Task(text));
}