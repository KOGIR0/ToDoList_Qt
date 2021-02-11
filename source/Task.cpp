#include "Task.h"

Task::Task(const QString& text, QWidget* parent) : QWidget(parent)
{
    QHBoxLayout* layout = new QHBoxLayout();

    QLabel* label = new QLabel(text);
    QPushButton* deleteBtn = new QPushButton("delete", this);

    connect(deleteBtn, &QPushButton::clicked, this, [=](){delete this;});

    layout->addWidget(label);
    layout->addWidget(deleteBtn);

    setLayout(layout);
}