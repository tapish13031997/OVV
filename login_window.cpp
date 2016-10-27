#include <first_window.h>
#include "ui_login_window.h"
#include <QMessageBox>
#include "initdb.h"
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
QSqlQuery query;
query.prepare("select * from voter");
query.exec();
while(query.next())
{
if(query.value(1).toString()==username && query.value(2).toString()==password)
{
    return true;
}
}
return false;
}
int login_window::login()
{


    username=ui->Username_lineEdit->text();
    password=ui->password_lineEdit->text();
     //QMessageBox messageBox;
    //messageBox.critical(0,"Error",username);
    if(check(username,password))
    {
         hide();
         name=username;
         vptr=new voter_window(this);
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



void login_window::on_commandLinkButton_clicked()
{

    first_window * fwptr;
    fwptr=new first_window(this);
        hide();
        fwptr->showMaximized();
}
