#ifndef ADD_PARTY_H
#define ADD_PARTY_H

#include <QDialog>

namespace Ui {
class add_party;
}

class add_party : public QDialog
{
    Q_OBJECT

public:
    explicit add_party(QWidget *parent = 0);
    ~add_party();

private slots:
    void on_submit_clicked();

    void on_back_clicked();

private:
    Ui::add_party *ui;
};

#endif // ADD_PARTY_H
