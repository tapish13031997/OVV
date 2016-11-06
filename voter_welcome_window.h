#ifndef VOTER_WELCOME_WINDOW_H
#define VOTER_WELCOME_WINDOW_H

#include <QMainWindow>
extern QString voter_name;
extern int areacode;
extern int myuid;
namespace Ui {
class voter_welcome_window;
}

class voter_welcome_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit voter_welcome_window(QWidget *parent = 0);
    ~voter_welcome_window();





private slots:
    void on_commandLinkButton_clicked();

    void on_pushButton_clicked();

    void showTimer();



    void on_pushButton_3_clicked();

private:
    Ui::voter_welcome_window *ui;
};

#endif // VOTER_WELCOME_WINDOW_H
