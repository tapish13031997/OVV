#ifndef VOTER_EDIT_H
#define VOTER_EDIT_H

#include <QDialog>
#include "manage_voter.h"
namespace Ui {
class voter_edit;
}

class voter_edit : public QDialog
{
    Q_OBJECT

public:
    explicit voter_edit(QWidget *parent = 0);
    void myvoter_edit(int uid);
    ~voter_edit();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::voter_edit *ui;
};

#endif // VOTER_EDIT_H
