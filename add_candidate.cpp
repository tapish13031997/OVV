#include "add_candidate.h"
#include "ui_add_candidate.h"
#include "manage_candidate.h"
#include "candidate.h"
#include "area.h"
#include "select_area.h"
#include "initdb.h"
#include <QMessageBox>
add_candidate::add_candidate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_candidate)
{
    ui->setupUi(this);
    QSqlQuery query;

    query.exec("select partyname from party");



    while(query.next())
    {
        QSqlQuery query2;

            query2.prepare("select * from candidate where party=:val1 and areacode=:val2");

                    query2.bindValue(":val1",query.value(0).toString());
                    query2.bindValue(":val2",A.areacode);

                    query2.exec();

                    if(query2.first())
                        continue;

           QString temp=query.value(0).toString();
           ui->party->addItem(temp);
    }
}

add_candidate::~add_candidate()
{
    delete ui;
}

void add_candidate::on_submit_clicked()
{

    QMessageBox::StandardButton reply;

    QSqlQuery query;

     Ctemp.name=ui->name->text();

     query.prepare("select areaname from area where areacode = :val");
     query.bindValue(":val",A.areacode);

     query.exec();

     query.first();

     QString nb=query.value(0).toString();

    QString s="Are you sure you want to add "+Ctemp.name+" to candidate list for "+nb;

    reply=QMessageBox::question(this,"CONFIRM",s,QMessageBox::Yes|QMessageBox::No);

    if(reply== QMessageBox::Yes)
    {



    Ctemp.party=ui->party->currentText();

    if(ui->male->isChecked())
        Ctemp.sex="M";
    else
        Ctemp.sex="F";

    QDate a=ui->dob->date();

    int x=a.day();
    int y=a.month();
    int z=a.year();

    if(x/10==0)
    Ctemp.DOB='0'+QString::number(x);
    else
    Ctemp.DOB=QString::number(x);

    Ctemp.DOB+='-';

    if(y/10==0)
    Ctemp.DOB+='0'+QString::number(y);
    else
    Ctemp.DOB+=QString::number(y);

    Ctemp.DOB+='-';

    Ctemp.DOB+=QString::number(z);

    Ctemp.areacode=A.areacode;

    QSqlQuery query;
    query.exec("select max(Cid) from candidate");

    query.first();

    Ctemp.Cid=query.value(0).toInt()+1;
        //qDebug()<<Ctemp.DOB;
    Ctemp.insert_candidate();

    s="Candidate "+Ctemp.name+" has been successfully registered for "+nb;

    QMessageBox hila;

   hila.information(this,"SUCCESSFUL",s);


    hide();
    select_area *it;
    it=new select_area;
    it->showMaximized();

}

}




void add_candidate::on_cancel_clicked()
{

    hide();
    manage_candidate *it;
    it=new manage_candidate;
    it->showMaximized();
}
