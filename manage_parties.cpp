#include "manage_parties.h"
#include "ui_manage_parties.h"
#include "initdb.h"
#include "add_party.h"
#include <QMessageBox>
#include "admin.h"
manage_parties::manage_parties(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manage_parties)
{
    ui->setupUi(this);


    setWindowTitle("Manage Political Parties");

    QSqlQuery query;

     //qDebug()<<A.areacode;

    query.prepare("select * from party");



    query.exec();

    while(query.next())
    {
            QString temp=query.value(0).toString();
            ui->pid->addItem(temp);

             temp=query.value(1).toString();
            ui->party_list->addItem(temp);


    }
}



manage_parties::~manage_parties()
{
    delete ui;
}

void manage_parties::on_insert_party_clicked()
{
    hide();
    add_party *it;
    it=new add_party;
    it->showFullScreen();


}

void manage_parties::on_delete_party_clicked()
{
    QListWidgetItem *it= ui->party_list->currentItem();

    QString t=it->text();


    QMessageBox::StandardButton reply;

    QString s="Are you sure you want to remove "+t+" from the party list";

    reply=QMessageBox::question(this,"CONFIRM",s,QMessageBox::Yes|QMessageBox::No);

    if(reply== QMessageBox::Yes)
    {

    QSqlQuery query;

    query.prepare("delete from party where partyname = :val1");

    query.bindValue(":val1",t);

    query.exec();

    hide();

    manage_parties *iti;
    iti = new manage_parties;
    iti->showMaximized();
}
}

void manage_parties::on_back_clicked()
{
    hide();
    admin *it;
    it=new admin;
    it->showMaximized();

}
