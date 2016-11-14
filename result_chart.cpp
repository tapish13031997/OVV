#include "result_chart.h"
#include "ui_result_chart.h"
#include <QPainter>
#include "initdb.h"
#include "area.h"
#include <QPushButton>
#include <QLineEdit>
#include <QPalette>
#include <QLabel>
result_chart::result_chart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::result_chart)
{
    ui->setupUi(this);
}

result_chart::~result_chart()
{
    delete ui;
}

void result_chart::paintEvent(QPaintEvent *)
{


    QVector<QColor> v(12);
    v[0]=Qt::red,v[1]=Qt::blue,v[2]=Qt::green,v[3]=Qt::yellow,v[4]=Qt::magenta,v[5]=Qt::gray,v[6]=Qt::darkRed,v[7]=Qt::darkCyan,
            v[8]=Qt::darkBlue,v[9]=Qt::darkGreen,v[10]=Qt::darkMagenta,v[11]=Qt::darkYellow;

    QPainter painter(this);

    QRectF size=QRectF(40,40,300,300);

    //painter.setBrush();
    QLineEdit *myBtn[100]; QLabel *l[100];QLabel *l2[100];
    /*myBtn=new QLineEdit(this);

    myBtn->setGeometry(400,40,20,20);
    QPalette palette;
    palette.setColor(QPalette::Base,Qt::red );
    myBtn->setPalette(palette);
    myBtn->setVisible(true);*/
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(5);
    painter.setPen(pen);

    QSqlQuery query,query2;

    query.prepare("select votecount from area_vote where areacode =:val");
    query.bindValue(":val",A.areacode);

    query.exec();

    query.first();

    double total_votes=query.value(0).toDouble(),start_angle=0.0,end_angle,angle;
    int i=0;
query.clear();

    query.prepare("select Cid from candidate where areacode =:val");

    query.bindValue(":val",A.areacode);

    //qDebug()<<A.areacode;

    query.exec();

       int cur=40;
    while(query.next())
    {
            query2.clear();
            query2.prepare("select votecount from candidate_vote where Cid=:val");
            query2.bindValue(":val",query.value(0).toInt());

            //qDebug()<<query.value(0).toInt()<<" "<<;

            query2.exec();

            query2.first();
            angle=query2.value(0).toDouble()/total_votes*360;

            qDebug()<<query.value(0).toInt()<<" "<<query2.value(0).toInt();

            end_angle=start_angle+angle;

            painter.setBrush(v[i]);

            painter.drawPie(size,start_angle*16,angle*16);

            start_angle=end_angle;





            myBtn[i]=new QLineEdit(this);

            myBtn[i]->setGeometry(400,cur,20,20);
            QPalette palette;
            palette.setColor(QPalette::Base,v[i] );
            myBtn[i]->setPalette(palette);
            myBtn[i]->setVisible(true);
            myBtn[i]->setDisabled(true);

            l[i]=new QLabel(this);
            l2[i]=new QLabel(this);

            l[i]->setGeometry(430,cur,120,20);
            l2[i]->setGeometry(560,cur,50,20);

            QSqlQuery queryi;

            queryi.prepare("select party from candidate where Cid=:val");
            queryi.bindValue(":val",query.value(0).toInt());

            queryi.exec();

            queryi.first();
      //      qDebug()<<queryi.lastQuery()<<' '<<query.value(0).toInt();


            l[i]->setText(queryi.value(0).toString());
            l2[i]->setText(query2.value(0).toString());

            l[i]->setVisible(true);
            l2[i]->setVisible(true);

             i++;
            cur+=60;

    }








}
