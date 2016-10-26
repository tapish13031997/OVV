#include "login_window.h"
#include "ui_login_window.h"
#include <QMessageBox>
login_window::login_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login_window)
{
    ui->setupUi(this);
}

login_window::~login_window()
{
    delete ui;
}

bool login_window::check(const QString &username,const QString &password)
{
    if(username=="T"&&password=="S")
    return true;
}
int login_window::login()
{
    QString username,password;
    vptr=new voter_window(this);

    username=ui->Username_lineEdit->text();
    password=ui->password_lineEdit->text();
    if(check(username,password))
    {
         hide();
        vptr->showMaximized();
        return 1;

    }
    else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Wrong Username/Password");
        messageBox.setFixedSize(500,200);
        return 0;
    }
}

void login_window::on_login_button_clicked()
{
        if(!login())
        {
                hide();
                uii =new login_window(this);
                uii->showMaximized();
        }

}


