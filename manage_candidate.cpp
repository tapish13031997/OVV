#include "manage_candidate.h"
#include "ui_manage_candidate.h"
#include<initdb.h>
#include"area.h"
#include"select_area.h"
#include <QMessageBox>
#include "modify_candidate.h"
#include "candidate.h"
candidate Ctemp;
manage_candidate::manage_candidate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manage_candidate)
{
    ui->setupUi(this);


    setWindowTitle("Manage Candidates");

    QSqlQuery query;

     //qDebug()<<A.areacode;

    query.prepare("select * from candidate where areacode = :val");
            query.bindValue(":val",A.areacode);

    query.exec();

    while(query.next())
    {
            QString temp=query.value(0).toString();
            ui->cid->addItem(temp);

             temp=query.value(1).toString();
            ui->candidate_name->addItem(temp);

             temp=query.value(2).toString();
            ui->candidate_party->addItem(temp);
    }



}



manage_candidate::~manage_candidate()
{
    delete ui;
}

void manage_candidate::on_remove_clicked()
{

    QListWidgetItem *it= ui->candidate_name->currentItem();

    QString t=it->text();


    QMessageBox::StandardButton reply;

    QString s="Are you sure you want to remove "+t+" from the candidate list";

    reply=QMessageBox::question(this,"CONFIRM",s,QMessageBox::Yes|QMessageBox::No);

    if(reply== QMessageBox::Yes)
    {

    QSqlQuery query;

    query.prepare("delete from candidate where areacode = :val1 and name = :val2");

    query.bindValue(":val1",A.areacode);

    query.bindValue(":val2",t);

    query.exec();

    hide();

    manage_candidate *iti;
    iti = new manage_candidate;
    iti->showMaximized();
}

    }

void manage_candidate::on_insert_candidate_clicked()
{

}

void manage_candidate::on_modify_clicked()
{
    hide();
    QListWidgetItem *it= ui->candidate_name->currentItem();

    QString t=it->text();

    QSqlQuery query;

    query.prepare("select * from candidate where name = :val");

    query.bindValue(":val",t);

    query.exec();

    query.first();

    Ctemp.Cid=query.value(0).toInt();
    Ctemp.name=query.value(1).toString();
    Ctemp.party=query.value(2).toString();
    Ctemp.sex=query.value(3).toString();
    Ctemp.DOB=query.value(4).toString();
    Ctemp.areacode=query.value(5).toInt();
    modify_candidate *jt;
    jt=new modify_candidate;
    jt->showMaximized();
}
