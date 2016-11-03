#ifndef LOGIN_WINDOW_H
#define LOGIN_WINDOW_H

#include <QMainWindow>
#include "voter_window.h"
#include "admin.h"
extern QString name;

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
    QString username,password;
    ~login_window();

private slots:
    void on_login_button_clicked();


    void on_commandLinkButton_clicked();

private:
    Ui::login_window *ui;
    login_window *uii;
    voter_window * vptr;
    admin * aptr;
};

#endif // LOGIN_WINDOW_H
