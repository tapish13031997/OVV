#include "manage_election.h"
#include "ui_manage_election.h"
#include "admin.h"
#include "election_time.h"
#include <QMessageBox>
#include <QDebug>
#include "result_chart.h"
#include "select_area.h"
#include "party_results.h"
election_time start_time,end_time;

Manage_Election::Manage_Election(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Manage_Election)
{
    ui->setupUi(this);

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

        qDebug()<<end_time.samay.date()<<' '<<end_time.samay.time()<<' '<<start_time.samay.date()<<' '<<start_time.samay.time()<<endl;
        qDebug()<<QDate::currentDate()<<' '<<QTime::currentTime()<<endl;

        hide();

        Manage_Election *it;
        it=new Manage_Election;
        it->showMaximized();
    }

}

void Manage_Election::on_stats_clicked()
{
    select_area *saptr;
    saptr=new select_area;
    saptr->showFullScreen();
}

void Manage_Election::on_save_clicked()
{


    QMessageBox::StandardButton reply;

    QString s="Are you sure you want to modify voting schedule ?";

    reply=QMessageBox::question(this,"CONFIRM",s,QMessageBox::Yes|QMessageBox::No);

    if(reply== QMessageBox::Yes)
    {

    start_time.samay=QDateTime(QDate(ui->start_date->date()),QTime(ui->start_time->time()));


    end_time.samay=QDateTime(QDate(ui->end_date->date()),QTime(ui->end_time->time()));


    //qDebug()<<start_time.samay.date().day()<<" "<<start_time.samay.date().month()<<" "<<start_time.samay.date().year();

    }
}
