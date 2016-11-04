#ifndef VOTER_WINDOW_H
#define VOTER_WINDOW_H

#include <QDialog>

namespace Ui {
class voter_window;
}

class voter_window : public QDialog
{
    Q_OBJECT

public:
    explicit voter_window(QWidget *parent = 0);
    ~voter_window();

private slots:
    void on_commandLinkButton_clicked();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::voter_window *ui;
    voter_window * vwptr;
    //vwptr=new voter_window(this);
};

#endif // VOTER_WINDOW_H
