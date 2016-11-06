#include "view_candidates.h"
#include "ui_view_candidates.h"
#include "area.h"
#include "candidate.h"
#include "initdb.h"
#include "voter_welcome_window.h"
#include "QMessageBox"
#include "vote.h"
view_candidates::view_candidates(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::view_candidates)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("select * from candidate where areacode =:val");
    query.bindValue(":val",areacode);
query.exec();
    while(query.next())
    {
        int temp=0;
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        while(temp<5)
        {
            QTableWidgetItem *it;
            it=new QTableWidgetItem(query.value(temp).toString());
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,temp,it);
            temp++;
        }

    }



}

view_candidates::~view_candidates()
{
    delete ui;
}

void view_candidates::on_commandLinkButton_clicked()
{
    hide();
    voter_welcome_window * vwwptr;
    vwwptr=new voter_welcome_window;
     vwwptr->showFullScreen();
}

void view_candidates::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply;

    int row=ui->tableWidget->currentRow();
 QTableWidgetItem *it;
 it=ui->tableWidget->item(row,0);
 QString s;
 int Cid;
 s=it->text();
 Cid=s.toInt();
 it=ui->tableWidget->item(row,1);
 s=it->text();
    s="Are you sure you want to vote "+s;

    reply=QMessageBox::question(this,"CONFIRM",s,QMessageBox::Yes|QMessageBox::No);

    if(reply== QMessageBox::Yes)
    {

            vote v;
            QSqlQuery query2;
            query2.prepare("insert into canvote values (:val1,1)");
            query2.bindValue(":val1",myuid);
            if(query2.exec())
                qDebug()<<query2.lastQuery();

            v.Cid=Cid;
            v.insert_vote();
            voter_welcome_window *vwwptr;
            vwwptr=new voter_welcome_window;
            vwwptr->showFullScreen();
            hide();
    }

}
