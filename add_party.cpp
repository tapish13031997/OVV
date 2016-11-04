#include "add_party.h"
#include "ui_add_party.h"
#include "initdb.h"
#include "party.h"
#include <QMessageBox>
#include "manage_parties.h"
add_party::add_party(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_party)
{
    ui->setupUi(this);



}

add_party::~add_party()
{
    delete ui;
}

void add_party::on_submit_clicked()
{
    party p;

    p.partyname=ui->party_name->text();

    QSqlQuery query;

    query.exec("select max(Pid) from party");

    query.first();

    p.Pid=query.value(0).toInt()+1;

    QMessageBox::StandardButton reply;

    QString s="Are you sure you want to add party "+p.partyname;

    reply=QMessageBox::question(this,"CONFIRM",s,QMessageBox::Yes|QMessageBox::No);

    bool flag=false;

    if(reply == QMessageBox::Yes)
    {
        query.prepare("insert into party values (:val1,:val2,0)");

        query.bindValue(":val1",p.Pid);
        query.bindValue(":val2",p.partyname);

        query.exec();

        flag=true;

        hide();

    }

    if(flag)
    {

        QMessageBox::information(this,"SUCCESSFUL","Successfully added "+p.partyname);

        manage_parties *it;
        it=new manage_parties;
        it->showMaximized();
    }
}

void add_party::on_back_clicked()
{
    hide();
}
