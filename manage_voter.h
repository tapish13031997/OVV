#ifndef MANAGE_VOTER_H
#define MANAGE_VOTER_H

#include <QMainWindow>
#include <QTableWidget>
#include "initdb.h"
#include "area.h"

namespace Ui {
class manage_voter;
}

class manage_voter : public QMainWindow
{
    Q_OBJECT

public:
    explicit manage_voter(QWidget *parent = 0);
    ~manage_voter();

private slots:
    void on_commandLinkButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::manage_voter *ui;
};

#endif // MANAGE_VOTER_H
