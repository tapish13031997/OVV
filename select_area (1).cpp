#include "select_area.h"
#include "ui_select_area.h"
#include "initdb.h"
#include "admin.h"
#include <QDebug>
#include "area.h"
#include "manage_candidate.h"
#include "QMessageBox"
#include "manage_voter.h"
#include "result_chart.h"
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

  //qDebug()<<s;

   query.prepare("select * from area where areaname = :val ");

   query.bindValue(":val",s);

   if(!query.exec())
   {
    QMessageBox myinfo;
    myinfo.critical(0,"ERROR","CANT EXECUTE");
}

   query.first();



      A.areacode=query.value(0).toInt();

    if(flag==1)
    {
           hide();

           manage_candidate *it;
           it=new manage_candidate;
           it->showMaximized();
    }
    else if(flag==2)
    {
        manage_voter *mvptr;
        hide();
            mvptr=new manage_voter(this);
        mvptr->showMaximized();
    }
    else
    if(flag==3)
    {
       result_chart *it;
       it=new result_chart;
       it->show();

    }
}

void select_area::on_cancel_clicked()
{
    hide();
    admin *it;
    it=new admin;
    it->showMaximized();
}
