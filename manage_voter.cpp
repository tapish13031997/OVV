#include "manage_voter.h"
#include "ui_manage_voter.h"
#include "admin.h"
#include "voter_edit.h"
manage_voter::manage_voter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manage_voter)
{
    ui->setupUi(this);
    QSqlQuery query;
  //  query.prepare("select * from voter where areaname =:val");
   // query.bindValue(":val",A.areacode);
//query.exec();
    query.exec("select * from voter");
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
voter_edit *veptr;
veptr=new voter_edit(this);
veptr->showNormal();

}
