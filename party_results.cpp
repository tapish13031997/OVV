#include "party_results.h"
#include "ui_party_results.h"
#include "initdb.h"
#include "QLabel"
#include "QLineEdit"
#include "select_area.h"
#include "admin.h"
party_results::party_results(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::party_results)
{
    ui->setupUi(this);

    QSqlQuery query,query1;

    query.prepare("select * from party_vote");

    query.exec();

    int cur=10;

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

        w[i]->setGeometry(20,cur,150 ,20);
        l[i]->setGeometry(175,cur,query.value(1).toInt()*5,20);


        w2[i]->setGeometry(175+query.value(1).toInt()*5+30,cur,30,20);
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
