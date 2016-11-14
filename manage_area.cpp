#include "manage_area.h"
#include "ui_manage_area.h"
#include "add_area.h"
#include "initdb.h"
#include <QMessageBox>
#include "admin.h"
manage_area::manage_area(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manage_area)
{
    ui->setupUi(this);
    setWindowTitle("Manage Political Parties");

    QSqlQuery query;



    query.prepare("select * from area");



    query.exec();

    while(query.next())
    {
            QString temp=query.value(0).toString();
            ui->areacode->addItem(temp);

             temp=query.value(2).toString();
            ui->area_list->addItem(temp);

            ui->population->addItem(query.value(1).toString());
    }
}

manage_area::~manage_area()
{
    delete ui;
}

void manage_area::on_insert_area_clicked()
{   hide();
    add_area *it;
    it=new add_area;
    it->showMaximized();
}

void manage_area::on_delete_area_clicked()
{
    QListWidgetItem *it= ui->area_list->currentItem();

    QString t=it->text();
    QMessageBox info;

    QMessageBox::StandardButton reply;

    QString s="Are you sure you want to remove "+t+" from the area list";

    reply=QMessageBox::question(this,"CONFIRM",s,QMessageBox::Yes|QMessageBox::No);

    if(reply== QMessageBox::Yes)
    {

            QSqlQuery query;

             query.prepare("select areacode from area where areaname =:val1");

            query.bindValue(":val1",t);

            query.exec();

            query.first();

            int x=query.value(0).toInt();

            query.prepare("delete from area where areacode =:val");
            query.bindValue(":val",x);

            query.exec();

             query.prepare("delete from candidate where areacode = :val");
             query.bindValue(":val",x);

             query.exec();

             query.prepare("delete from voter where areacode = :val");
             query.bindValue(":val",x);

             query.exec();








            hide();

            manage_area *iti;
            iti = new manage_area;
            iti->showMaximized();


    }
}

void manage_area::on_back_clicked()
{
    hide();
    admin *it;
    it=new admin;
    it->showMaximized();
}
