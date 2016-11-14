#include "manage_election.h"
#include "ui_manage_election.h"
#include "admin.h"
#include "election_time.h"
#include <QMessageBox>
#include <QDebug>
#include "result_chart.h"
#include "select_area.h"
#include "party_results.h"
#include "view_stats.h"
#include "initdb.h"
election_time start_time,end_time;

Manage_Election::Manage_Election(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Manage_Election)
{
    ui->setupUi(this);
 QSqlQuery query2;
 query2.exec("select * from TIMER");
 if(query2.first())
 {
        start_time.samay= QDateTime(query2.value(0).toDate(),QTime(query2.value(1).toInt(),query2.value(2).toInt(),query2.value(3).toInt()));
        query2.next();
        end_time.samay= QDateTime(query2.value(0).toDate(),QTime(query2.value(1).toInt(),query2.value(2).toInt(),query2.value(3).toInt()));

 }
 else
 {
         start_time.samay=QDateTime(QDate(2016,11,7),QTime(20,0,0));
         end_time.samay=QDateTime(QDate(2016,11,7),QTime(20,0,0));
 }
    ui->start_date->setDate(start_time.samay.date());

     ui->start_time->setTime(start_time.samay.time());

     ui->end_date->setDate(end_time.samay.date());

     ui->end_time->setTime(end_time.samay.time());


}

Manage_Election::~Manage_Election()
{
    delete ui;
}

void Manage_Election::on_result_clicked()
{
    /*flag=3;
        hide();
        select_area *it;
        it=new select_area;
        it->showMaximized();*/

        hide();
        party_results *it;
        it=new party_results;
        it->showFullScreen();
}

void Manage_Election::on_back_clicked()
{
    hide();
    admin *it;
    it=new admin;
    it->showMaximized();
}

void Manage_Election::on_abort_clicked()
{

    QMessageBox::StandardButton reply;

    QString s="Are you sure you want to abort elections ?";

    reply=QMessageBox::question(this,"CONFIRM",s,QMessageBox::No|QMessageBox::Yes);

    if(reply== QMessageBox::Yes)
    {


        end_time.samay=QDateTime::currentDateTime();

        start_time.samay=QDateTime::currentDateTime();

      //  qDebug()<<end_time.samay.date()<<' '<<end_time.samay.time()<<' '<<start_time.samay.date()<<' '<<start_time.samay.time()<<endl;
       // qDebug()<<QDate::currentDate()<<' '<<QTime::currentTime()<<endl;

        hide();

        Manage_Election *it;
        it=new Manage_Election;
        it->showMaximized();
    }

}

void Manage_Election::on_stats_clicked()
{
view_stats *vsptr;
vsptr=new view_stats;
vsptr->showMaximized();
}

void Manage_Election::on_save_clicked()
{
QSqlQuery resetquery;
resetquery.exec("update candidate_vote set votecount=0");
resetquery.clear();
resetquery.exec("update area_vote set votecount=0");
resetquery.clear();
//resetquery.exec("delete from party_vote"); WE DONT HAVE TO RESET PARTY_VOTE AS ITS IS CREATED IN ADD PARTY.cpp and you reset it each time you create a new party;
//resetquery.clear();
resetquery.exec("delete from canvote");
resetquery.clear();

    QMessageBox::StandardButton reply;

    QString s="Are you sure you want to modify voting schedule ?";

    reply=QMessageBox::question(this,"CONFIRM",s,QMessageBox::Yes|QMessageBox::No);
QTime mytime=ui->start_time->time();
    if(reply== QMessageBox::Yes)
    {
        QSqlQuery query;
        query.exec("delete from TIMER");
        query.clear();
        int hrs,mins,sec;
        hrs=mytime.hour();
        mins=mytime.minute();
        sec=mytime.second();
        query.prepare("insert into TIMER values(:date,:hrs,:mins,:sec)");
        query.bindValue(":date",ui->start_date->date());
        query.bindValue(":hrs",hrs);query.bindValue(":mins",mins);query.bindValue(":sec",sec);
        query.exec();
    start_time.samay=QDateTime(QDate(ui->start_date->date()),QTime(ui->start_time->time()));
query.clear();
mytime=ui->end_time->time();
    end_time.samay=QDateTime(QDate(ui->end_date->date()),QTime(ui->end_time->time()));
    hrs=mytime.hour();
    mins=mytime.minute();
    sec=mytime.second();
    query.prepare("insert into TIMER values(:date,:hrs,:mins,:sec)");
    query.bindValue(":date",ui->end_date->date());
    query.bindValue(":hrs",hrs);query.bindValue(":mins",mins);query.bindValue(":sec",sec);
    query.exec();

    //qDebug()<<start_time.samay.date().day()<<" "<<start_time.samay.date().month()<<" "<<start_time.samay.date().year();

    }

}
