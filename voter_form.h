#ifndef VOTER_FORM_H
#define VOTER_FORM_H

#include <QMainWindow>

namespace Ui {
class voter_form;
}

class voter_form : public QMainWindow
{
    Q_OBJECT

public:
    explicit voter_form(QWidget *parent = 0);
    ~voter_form();

private:
    Ui::voter_form *ui;
};

#endif // VOTER_FORM_H
