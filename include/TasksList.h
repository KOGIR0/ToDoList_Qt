#ifndef TASKSLIST
#define TASKSLIST

#include <QWidget>
#include <QVBoxLayout>
#include <QString>
#include <vector>

class TasksList : public QWidget
{
public:
    TasksList(QWidget* parent = 0);
    void addTask(const QString& text);
    std::vector<QString> getTasks();

private:
    QVBoxLayout* layout;
};

#endif