#include "first_window.h"
#include "ui_voter_window.h"
#include "voter_window.h"
#include "login_window.h"
#include "initdb.h"
#include "voter_form.h"
#include <QMessageBox>
QString name;
voter_window::voter_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::voter_window)
{

    ui->setupUi(this);
    ui->lineEdit_name->setText(name);
    ui->lineEdit_password->setText("************");
   QSqlQuery query3,query2;
    query3.prepare("select * from voter where username =:val");
    query3.bindValue(":val",name);
    query3.exec();
    query3.first();
ui->lineEdit_name->setText(query3.value(3).toString());
ui->lineEdit_DOB->setText(query3.value(6).toString());
ui->lineEdit_sex->setText(query3.value(5).toString());
ui->lineEdit_phone->setText(query3.value(7).toString());
ui->lineEdit_username->setText(query3.value(1).toString());
query2.prepare("select * from area where areacode =:val");
query2.bindValue(":val",query3.value(4).toInt());
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

void voter_window::on_pushButton_clicked()
{

}

void voter_window::on_pushButton_2_clicked()
{
    voter_form *vfptr;
    vfptr=new voter_form(this);
    vfptr->myvoter_edit(ui->lineEdit_username->text());
}
