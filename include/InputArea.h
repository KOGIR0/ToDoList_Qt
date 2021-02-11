#ifndef INPUTAREA
#define INPUTAREA

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>

class InputArea : public QWidget
{
public:
    InputArea(QWidget* parent = 0);

private:
    QGridLayout* layout;
    QLineEdit* textField;
};

#endif