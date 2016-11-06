#include "add_area.h"
#include "ui_add_area.h"
#include "area.h"
#include "manage_area.h"
#include "initdb.h"
#include "QMessageBox"
add_area::add_area(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_area)
{


    ui->setupUi(this);
}

add_area::~add_area()
{
    delete ui;
}

void add_area::on_submit_clicked()
{
    area a;

    a.areaname=ui->area_name->text();

    QSqlQuery query;

    query.exec("select max(areacode) from area");

    query.first();

    a.areacode=query.value(0).toInt()+1;

    QMessageBox::StandardButton reply;

    QString s="Are you sure you want to add area "+a.areaname;

    reply=QMessageBox::question(this,"CONFIRM",s,QMessageBox::Yes|QMessageBox::No);

    bool flag=false;

    if(reply == QMessageBox::Yes)
    {
        query.prepare("insert into area values (:val1,0,:val2)");

        query.bindValue(":val1",a.areacode);
        query.bindValue(":val2",a.areaname);


        query.exec();

        flag=true;



    }

    if(flag)
    {

        QMessageBox::information(this,"SUCCESSFUL","Successfully added "+a.areaname);

        manage_area *it;
        it=new manage_area(this);
        it->showMaximized();
    }

    hide();
}

void add_area::on_back_clicked()
{
    hide();
    manage_area *it;
    it=new manage_area(this);
    it->showMaximized();
}
