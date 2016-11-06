#include "view_stats.h"
#include "ui_view_stats.h"
#include "initdb.h"
#include "QProgressBar"
#include "QLabel"

view_stats::view_stats(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::view_stats)
{
    ui->setupUi(this);
    QSqlQuery query1;
    query1.exec("select areacode,areaname from area");
    QProgressBar * qpb[1000];
    QLabel * ql[1000];
    int i=0,x=10,y=100;
    while(query1.next())
    {
            qpb[i]=new QProgressBar(this);
            qpb[i]->setOrientation(Qt::Horizontal);
            QSqlQuery tq;
            tq.prepare("select count(*) from canvote where areacode = :val ");
            tq.bindValue(":val",query1.value(0).toInt());
               double percentage;
               tq.exec();
               tq.first();
               percentage=tq.value(0).toDouble();
               tq.clear();
               tq.prepare("select population from area where areacode =:val");
               tq.bindValue(":val",query1.value(0).toInt());
               tq.exec();
               tq.first();
               percentage=percentage/tq.value(0).toDouble();
               percentage*=100;
                    //code for qlable
               ql[i]=new QLabel(this);
               ql[i]->setText(query1.value(1).toString());
               ql[i]->setGeometry(x,y,100,20);



               //code ends
            qpb[i]->setValue(percentage);
                qpb[i]->setVisible(true);
                qpb[i]->setGeometry(x+110,y,200,20);
            y+=40;
        i++;
    }

}

view_stats::~view_stats()
{
    delete ui;
}
