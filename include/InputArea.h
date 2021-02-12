#ifndef INPUTAREA
#define INPUTAREA

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QString>
#include <vector>

#include "TasksList.h"
class InputArea : public QWidget
{
public:
    InputArea(QWidget* parent = 0);
    std::vector<QString> getTasks();

private:
    TasksList* list;
    QGridLayout* layout;
    QLineEdit* textField;
};

#endif