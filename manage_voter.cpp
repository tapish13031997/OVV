#include "ui_manage_voter.h"
#include "admin.h"
#include <QTableWidgetItem>
#include "QMessageBox"
#include "initdb.h"
#include "area.h"
#include "manage_voter.h"
manage_voter::manage_voter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manage_voter)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("select * from voter where areacode =:val");
    query.bindValue(":val",A.areacode);
query.exec();
//qDebug()<<query.lastError()<<' '<<A.areacode<<endl;
//    query.exec("select * from voter");
    while(query.next())
    {
        int temp=0;
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        QStringList data;
        while(temp<8)
        {
            QTableWidgetItem *it;
            it=new QTableWidgetItem(query.value(temp).toString());
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,temp,it);
            temp++;
        }

    }


}

manage_voter::~manage_voter()
{
    delete ui;
}

void manage_voter::on_commandLinkButton_clicked()
{
    hide();
    admin *aptr;
    aptr=new admin(this);
    aptr->showMaximized();

}

void manage_voter::on_pushButton_clicked()
{

    int row=ui->tableWidget->currentRow();
 QTableWidgetItem *it;
 it=ui->tableWidget->item(row,0);
 QString s;
 int uid;
 s=it->text();
 uid=s.toInt();
QSqlQuery query;
query.prepare("delete from voter where uid = :val");
query.bindValue(":val",uid);

if(!query.exec())
{
    QMessageBox inform;
    inform.critical(0,"ERROR","CONTACT ADMIN");
}
else
{
    QMessageBox inform;
    inform.information(0,"REMOVED","Voter "+s);
    ui->tableWidget->removeRow(row);
}
hide();
    manage_voter *mvptr;
    mvptr=new manage_voter(this);
    mvptr->showMaximized();
}

