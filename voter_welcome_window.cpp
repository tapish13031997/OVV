#include "voter_welcome_window.h"
#include "ui_voter_welcome_window.h"
#include "login_window.h"
#include "voter_window.h"
#include "view_candidates.h"
#include "initdb.h"
#include "QMessageBox"
int areacode;
int myuid;
voter_welcome_window::voter_welcome_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::voter_welcome_window)
{
    ui->setupUi(this);
    ui->lineEdit->setText(name);//name is actually username not name;
    QSqlQuery query1;
    query1.prepare("select areacode,Uid from voter where username =:val ");
    query1.bindValue(":val",name);
    if(!query1.exec())
    {
        QMessageBox info;
        info.critical(0,"ERROR","CONTACT ADMIN");
    }
    else
    {
            query1.first();
            areacode=query1.value(0).toInt();
            myuid=query1.value(1).toInt();
    }
QSqlQuery query2;
    query2.prepare("select * from canvote where Uid =:val1");
    query2.bindValue(":val1",myuid);
    query2.exec();
    if(query2.first())
    {
       ui->pushButton_3->setDisabled(1);
    }
}

voter_welcome_window::~voter_welcome_window()
{
    delete ui;
}

void voter_welcome_window::on_commandLinkButton_clicked()
{
       hide();
    login_window *lwptr;
    lwptr=new login_window(this);
    lwptr->showMaximized();
}

void voter_welcome_window::on_pushButton_clicked()
{
    hide();
        voter_window *vw;
        vw=new voter_window(this);
        vw->showMaximized();
}

void voter_welcome_window::on_pushButton_3_clicked()
{
    hide();
    view_candidates * vcptr;
    vcptr=new view_candidates;
    vcptr->showFullScreen();
}
