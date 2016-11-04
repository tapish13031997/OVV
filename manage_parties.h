#ifndef MANAGE_PARTIES_H
#define MANAGE_PARTIES_H

#include <QDialog>

namespace Ui {
class manage_parties;
}

class manage_parties : public QDialog
{
    Q_OBJECT

public:
    explicit manage_parties(QWidget *parent = 0);
    ~manage_parties();

private slots:
    void on_insert_party_clicked();

    void on_delete_party_clicked();

    void on_back_clicked();

private:
    Ui::manage_parties *ui;
};

#endif // MANAGE_PARTIES_H
