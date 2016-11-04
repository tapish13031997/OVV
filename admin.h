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
void on_voters_clicked();
    void on_commandLinkButton_clicked();

    void on_areas_2_clicked();

    void on_areas_clicked();

private:
    Ui::admin *ui;
};
extern int flag;
#endif // ADMIN_H
