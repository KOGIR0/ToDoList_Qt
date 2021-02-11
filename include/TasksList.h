#ifndef TASKSLIST
#define TASKSLIST

#include <QWidget>
#include <QVBoxLayout>

class TasksList : public QWidget
{
public:
    TasksList(QWidget* parent = 0);
    void addTask(const QString& text);

private:
    QVBoxLayout* layout;
};

#endif