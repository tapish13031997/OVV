#include "voter_edit.h"
#include "ui_voter_edit.h"
#include "voter_form.h"
#include "QMessageBox"
#include "initdb.h"
voter_edit::voter_edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::voter_edit)
{
    ui->setupUi(this);
}

voter_edit::~voter_edit()
{
    delete ui;
}

void voter_edit::on_pushButton_clicked()
{
int uid;
uid=ui->lineEdit->text().toInt();
QSqlQuery query;
query.clear();
query.prepare("select * from voter where uid=:val");
query.bindValue(":val",uid);
query.exec();
if(!query.first())
{
    QMessageBox error_msg;
    error_msg.critical(0,"ERROR","UID NOT FOUND!");
    hide();
    voter_edit *tveptr;
    tveptr=new voter_edit(this);
    tveptr->show();
}
hide();
myvoter_edit(uid);
}

void voter_edit::on_pushButton_2_clicked()
{

}
