#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>

namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = 0);
    ~admin();

private slots:
    void on_candidates_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::admin *ui;
};
extern int flag;
#endif // ADMIN_H
