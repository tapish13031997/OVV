#include "select_area.h"
#include "ui_select_area.h"

#include "initdb.h"
#include "admin.h"
#include <QDebug>
#include "area.h"
#include "manage_candidate.h"
area A;

select_area::select_area(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::select_area)
{
    ui->setupUi(this);

    setWindowTitle("Select Area");

    QSqlQuery query;

    query.exec("select areaname from area");



    while(query.next())
    {
           QString temp=query.value(0).toString();
           ui->arealist->addItem(temp);
    }
    //ui->arealist->setCurrentRow(0);



}

select_area::~select_area()
{
    delete ui;
}

void select_area::on_next_clicked()
{
    QListWidgetItem *itm=ui->arealist->currentItem();

   QString s=itm->text();

   QSqlQuery query;

  // qDebug()<<s;

   query.exec("select * from area where areaname =:val");

   query.bindValue(":val",s);

   query.exec();

   query.first();



      A.areacode=query.value(0).toInt();

      //qDebug()<<A.areacode;

    /*manage_candidate *it;
    it=new manage_candidate;
    hide();
    it->showMaximized();*/
//qDebug()<<flag;

    if(flag==1)
    {
           hide();

           manage_candidate *it;
           it=new manage_candidate;
           it->showMaximized();
    }
}

void select_area::on_cancel_clicked()
{
    hide();
    admin *it;
    it=new admin;
    it->showMaximized();
}
