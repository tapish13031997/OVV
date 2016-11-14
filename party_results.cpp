#include "party_results.h"
#include "ui_party_results.h"
#include "initdb.h"
#include "QLabel"
#include "QLineEdit"
#include "select_area.h"
#include "admin.h"
#include "manage_election.h"
party_results::party_results(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::party_results)
{
    ui->setupUi(this);

    QSqlQuery query,query1,query2,query3,query4;

    query.exec("update party_vote set votecount=0");

    query.prepare("select areacode from area");

    query.exec();

    while(query.next())
    {
        int x=query.value(0).toInt();
        query1.prepare("select Cid from candidate_vote where areacode=:val1 and votecount= (select max(votecount) from candidate_vote where areacode=:val)");
        query1.bindValue(":val",x);
        query1.bindValue(":val1",x);
        //qDebug()<<x;


        if(!query1.exec())
            qDebug()<<query1.lastError();

        query1.first();

       //qDebug()<<query1.value(0).toInt();

        query2.prepare("select party from candidate where Cid=:val");
        query2.bindValue(":val",query1.value(0).toInt());
        query2.exec();
        query2.first();

        //qDebug()<<query2.value(0).toString();

        query3.prepare("select Pid from party where partyname =:val");
        query3.bindValue(":val",query2.value(0).toString());
        query3.exec();

        query3.first();

        //qDebug()<<query3.value(0).toInt();

        query4.prepare("update party_vote set votecount=votecount+1 where Pid=:val");
        query4.bindValue(":val",query3.value(0).toInt());

        query4.exec();


    }

    query.prepare("select * from party_vote");

    query.exec();

    int cur=10;
    int x=200;
    int y=200;
    int i=0;
    
    QLabel *w[100],*w2[100]; QLineEdit *l[100];

    while(query.next())
    {
        query1.prepare("select partyname from party where Pid=:val");
        query1.bindValue(":val",query.value(0).toInt());
        //qDebug()<<query.value(0).toInt();

        w[i]=new QLabel(this);
        l[i]=new QLineEdit(this);
        w2[i]=new QLabel(this);

        query1.exec();
        query1.first();

        w[i]->setGeometry(x+20,y+cur,150 ,20);
        l[i]->setGeometry(x+175,y+cur,query.value(1).toInt()*20,20);


        w2[i]->setGeometry(x+175+query.value(1).toInt()*20+30,y+cur,30,20);
        w2[i]->setText(query.value(1).toString());
        w2[i]->setVisible(true);

        cur+=40;
        QPalette palette;
        palette.setColor(QPalette::Base,Qt::green);

        l[i]->setPalette(palette);
        l[i]->setVisible(true);
        l[i]->setDisabled(true);


        w[i]->setText(query1.value(0).toString());
        //qDebug()<<query1.value(0).toString();

        w[i]->setVisible(true);

        i++;
    }

}

party_results::~party_results()
{
    delete ui;
}

void party_results::on_pushButton_clicked()
{
        flag=3;
        hide();
        select_area *it;
        it=new select_area;
        it->showMaximized();
}

void party_results::on_pushButton_2_clicked()
{
    hide();
    Manage_Election *it;
    it=new Manage_Election;
     it->showFullScreen();

}

