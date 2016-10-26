#ifndef LOGIN_WINDOW_H
#define LOGIN_WINDOW_H

#include <QMainWindow>
#include <voter_window.h>
namespace Ui {
class login_window;
}

class login_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit login_window(QWidget *parent = 0);
    bool check(const QString &username,const QString &password);
    int login();
    ~login_window();

private slots:
    void on_login_button_clicked();


private:
    Ui::login_window *ui;
    login_window *uii;
    voter_window * vptr;
};

#endif // LOGIN_WINDOW_H
