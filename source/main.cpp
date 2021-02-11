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

class Task : public QWidget
{
public:
    Task(const QString& text, QWidget* parent = 0) : QWidget(parent)
    {
        QHBoxLayout* layout = new QHBoxLayout();

        QLabel* label = new QLabel(text);
        QPushButton* deleteBtn = new QPushButton("delete", this);

        connect(deleteBtn, &QPushButton::clicked, this, [=](){delete this;});

        layout->addWidget(label);
        layout->addWidget(deleteBtn);

        setLayout(layout);
    }
};

class TasksList : public QWidget
{
public:
    TasksList(QWidget* parent = 0) : QWidget(parent)
    {
        layout = new QVBoxLayout();

        layout->addWidget(new Task("some task"));

        setLayout(layout);
    }

    void addTask(const QString& text)
    {
        layout->addWidget(new Task(text));
    }

private:
    QVBoxLayout* layout;
};

class InputArea : public QWidget
{
public:
    InputArea(QWidget* parent = 0) : QWidget(parent)
    {
        layout = new QGridLayout();
        
        QPushButton* addBtn = new QPushButton("Add", this);
        textField = new QLineEdit(this);
        TasksList* list = new TasksList();

        connect(addBtn, &QPushButton::clicked, list, [=](){list->addTask(textField->text());});
        
        layout->addWidget(textField, 0, 0, 1, 1);
        layout->addWidget(addBtn, 0, 1, 1, 1);
        layout->addWidget(list, 1, 0, 3, 3);

        setLayout(layout);
    }

private:
    QGridLayout* layout;
    QLineEdit* textField;
};

class MainWindow : public QMainWindow
{
public:
    MainWindow()
    {
        InputArea* ia = new InputArea();
        
        QScrollArea* scrollArea = new QScrollArea(this);
        scrollArea->setWidget(ia);
        scrollArea->setAlignment(Qt::AlignHCenter);

        setCentralWidget(ia);
    }

private:

};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.resize(200, 200);
    window.setWindowTitle("Task app");
    window.show();

    return app.exec();
}