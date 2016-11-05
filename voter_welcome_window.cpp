#include "voter_welcome_window.h"
#include "ui_voter_welcome_window.h"
#include "login_window.h"
#include "voter_window.h"
#include "view_candidates.h"
#include "initdb.h"
#include "QMessageBox"
#include "election_time.h"
#include <QTimer>
#include <QDebug>

int areacode;
int myuid;
bool fag;
QString secondsToString(int seconds)
 {//qDebug()<<seconds;
   const qint64 DAY = 86400;
   qint64 days = seconds / DAY;
   QTime t = QTime(0,0).addSecs(seconds % DAY);
   return QString("%1 days, %2 hours, %3 minutes, %4 seconds")
    .arg(days).arg(t.hour()).arg(t.minute()).arg(t.second());
}

voter_welcome_window::voter_welcome_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::voter_welcome_window)
{
    ui->setupUi(this);
    ui->lineEdit->setText(name);//name is actually username not name;

        //qDebug()<<start_time.samay.date().day()<<" "<<start_time.samay.date().month()<<" "<<start_time.samay.date().year();

        if((start_time.samay.date() < QDate::currentDate()) or (start_time.samay.date() ==QDate::currentDate() and start_time.samay.time() > QTime::currentTime()))
        {
            ui->start_end->setText("Election Starts in");

                    fag=false;

        }
        else if(start_time.samay.date() ==QDate::currentDate() and end_time.samay.time() > QTime::currentTime())
            {
                ui->start_end->setText("Election Ends in");


                fag=true;
              \

            }
         QTimer *timer=new QTimer(this);
            connect(timer,SIGNAL(timeout()),this,SLOT(showTimer()));
            timer->start();
    QSqlQuery query1;
    query1.prepare("select areacode,Uid from voter where username =:val ");
    query1.bindValue(":val",name);
    if(!query1.exec())
    {
        QMessageBox info;
        info.critical(0,"ERROR","CONTACT ADMIN");
    }
    else
    {
            query1.first();
            areacode=query1.value(0).toInt();
            myuid=query1.value(1).toInt();
    }
QSqlQuery query2;
    query2.prepare("select * from canvote where Uid =:val1");
    query2.bindValue(":val1",myuid);
    query2.exec();
    if(query2.first())
    {
       ui->pushButton_3->setDisabled(1);
    }
}
void voter_welcome_window::showTimer()
 {
     if(fag==false)
     {
                 QDateTime a=start_time.samay;
                  QDateTime b=QDateTime::currentDateTime();


                  ui->election_timer->setText(secondsToString(b.secsTo(a)));
        }
     else
     {

                  QDateTime b=end_time.samay;
                  QDateTime a=QDateTime::currentDateTime();


                  ui->election_timer->setText(secondsToString(a.secsTo(b)));

     }
}
  voter_welcome_window::~voter_welcome_window()
{
    delete ui;
}

void voter_welcome_window::on_commandLinkButton_clicked()
{
       hide();
    login_window *lwptr;
    lwptr=new login_window(this);
    lwptr->showMaximized();
}

void voter_welcome_window::on_pushButton_clicked()
{
    hide();
        voter_window *vw;
        vw=new voter_window(this);
        vw->showMaximized();
}

void voter_welcome_window::on_pushButton_3_clicked()
{
    hide();
    view_candidates * vcptr;
    vcptr=new view_candidates;
    vcptr->showFullScreen();
}
