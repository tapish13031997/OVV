#ifndef VOTER_FORM_H
#define VOTER_FORM_H

#include <QMainWindow>
#include "voter_window.h"

namespace Ui {
class voter_form;
}

class voter_form : public QMainWindow
{
    Q_OBJECT

public:
    explicit voter_form(QWidget *parent = 0);

    void voter_edit(int uid);
    ~voter_form();

private slots:
    void on_submit_clicked();
    
    void on_cancel_clicked();
    
private:
    Ui::voter_form *ui;
    voter_window *it;
    voter_form *vfptr;
    //first_window *jt;

};

#endif // VOTER_FORM_H
