#ifndef TASK
#define TASK

#include <QWidget>
#include <QString>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

class Task : public QWidget
{
public:
    Task(const QString& text, QWidget* parent = 0);
};

#endif