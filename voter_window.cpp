#include "first_window.h"
#include "ui_voter_window.h"
#include "voter_window.h"
#include "login_window.h"
#include "initdb.h"
#include <QMessageBox>
QString name;
voter_window::voter_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::voter_window)
{

    ui->setupUi(this);
    ui->lineEdit_name->setText(name);
    ui->lineEdit_password->setText("************");
   QSqlQuery query,query2;
    query.prepare("select * from voter where username =:val");
    query.bindValue(":val",name);
    query.exec();
    query.first();
ui->lineEdit_name->setText(query.value(3).toString());
ui->lineEdit_DOB->setText(query.value(6).toString());
ui->lineEdit_sex->setText(query.value(5).toString());
ui->lineEdit_phone->setText(query.value(7).toString());
ui->lineEdit_username->setText(query.value(1).toString());
query2.prepare("select * from area where areacode =:val");
query2.bindValue(":val",query.value(4).toInt());
query2.exec();
query2.first();
ui->lineEdit_area->setText(query2.value(2).toString());

}

voter_window::~voter_window()
{
    delete ui;
}


void voter_window::on_commandLinkButton_clicked()
{
    hide();
    first_window *fwptr;
    fwptr=new first_window(this);
    fwptr->showMaximized();
}
