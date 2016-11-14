#include "modify_candidate.h"
#include "ui_modify_candidate.h"
#include "manage_candidate.h"
#include "initdb.h"
#include <QMessageBox>
#include "candidate.h"
#include "area.h"
//candidate Ctemp;
//area A;
modify_candidate::modify_candidate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modify_candidate)
{
    ui->setupUi(this);

    QSqlQuery query;

    query.exec("select partyname from party");

    int t=0,fin=0;

    while(query.next())
    {
           QString temp=query.value(0).toString();

           ++t;

           if(temp==Ctemp.party)
           {
               fin=t;
           }

           ui->party->addItem(temp);
    }

        ui->party->setCurrentIndex(fin);

        ui->name->setText(Ctemp.name);

        if(Ctemp.sex=="M")
            ui->male->click();


        QStringRef y;
        int df1,df2,df3;

       // qDebug()<<Ctemp.DOB;

        y=Ctemp.DOB.midRef(0,2);

        //qDebug()<<y<<" ";
        df1=y.toString().toInt();

        //d.y=df;
        y=Ctemp.DOB.midRef(3,2);
        //qDebug()<<y<<" ";
        df2=y.toString().toInt();

        //d.m=df;
        y=Ctemp.DOB.midRef(6,4);
       // qDebug()<<y<<" ";
        df3=y.toString().toInt();

        //d.d=df;

        QDate d(df3,df2,df1);

       // qDebug()<<df3<<" "<<df2<<" "<<df1;

        ui->dob->setDate(d);


}

modify_candidate::~modify_candidate()
{
    delete ui;
}


void modify_candidate::on_modify_clicked()
{

    QMessageBox::StandardButton reply;

    QSqlQuery query;

    QString s="Are you sure you want to modify credentials of "+Ctemp.name;

    reply=QMessageBox::question(this,"CONFIRM",s,QMessageBox::Yes|QMessageBox::No);

    if(reply== QMessageBox::Yes)
    {
            QSqlQuery query2;
        query2.prepare("delete from candidate_vote where Cid =:val ");
        query2.bindValue(":val",Ctemp.Cid);
            query.prepare("delete from candidate where areacode = :val1 and name = :val2");

            query.bindValue(":val1",A.areacode);

            query.bindValue(":val2",Ctemp.name);

            query.exec();

            Ctemp.name=ui->name->text();

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


                //qDebug()<<Ctemp.DOB;
            Ctemp.insert_candidate();

    }
}

void modify_candidate::on_cancel_clicked()
{
    hide();
    manage_candidate *it;
    it=new manage_candidate;
    it->showMaximized();
}
