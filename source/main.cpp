#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QScrollArea>

class InputArea : public QWidget
{
public:
    InputArea()
    {
        QHBoxLayout* layout = new QHBoxLayout();
        
        QPushButton* addBtn = new QPushButton("Add", this);
        QLabel* textField = new QLabel("Text", this);

        layout->addWidget(textField);
        layout->addWidget(addBtn);

        setLayout(layout);
    }
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

        setCentralWidget(scrollArea);
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