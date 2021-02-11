#include "InputArea.h"
#include "TasksList.h"

#include <QPushButton>
#include <QScrollArea>

InputArea::InputArea(QWidget* parent) : QWidget(parent)
{
    layout = new QGridLayout();
    
    QPushButton* addBtn = new QPushButton("Add", this);
    textField = new QLineEdit(this);
    TasksList* list = new TasksList();
    list->setStyleSheet("QWidget { background-color: gray; }");

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidget(list);
    scrollArea->setAlignment(Qt::AlignHCenter);
    scrollArea->setWidgetResizable(true);

    connect(addBtn, &QPushButton::clicked, list, [=](){list->addTask(textField->text());});
    
    layout->addWidget(textField, 0, 0, 1, 1);
    layout->addWidget(addBtn, 0, 1, 1, 1);
    layout->addWidget(scrollArea, 1, 0, 3, 3);

    setLayout(layout);
}