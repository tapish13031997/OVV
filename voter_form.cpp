#include "voter_form.h"
#include "ui_voter_form.h"
#include "voter.h"
#include "initdb.h"
#include "first_window.h"
#include "QMessageBox"
voter_form::voter_form(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::voter_form)
{
    ui->setupUi(this);


    QSqlQuery query;

    query.exec("select areaname from area");



    while(query.next())
    {
           QString temp=query.value(0).toString();
           ui->area->addItem(temp);
    }

}

voter_form::~voter_form()
{
    delete ui;
}

void voter_form::on_submit_clicked()
{
    voter v;

    v.password=ui->password->text();

    QString repassword=ui->repassword->text();

    if(v.password!=repassword)
    {QMessageBox::information(this,"WARNING","Passwords do not match"); return;}

    v.name=ui->name->text();

    v.username=ui->username->text();





    if(ui->Male->isChecked())
        v.sex="M";
    else
        v.sex="F";

    QString temp;
    temp=ui->area->currentText();

    QSqlQuery query;

    query.prepare("select areacode from area where areaname =:val");
    query.bindValue(":val",temp);


   if(!query.exec())
    qDebug()<<query.lastError();

    query.first();
    v.areacode=query.value(0).toInt();

    v.phone=ui->phone->text();

    QDate a=ui->DOB->date();

    int x=a.day();
    int y=a.month();
    int z=a.year();

    v.DOB+=QString::number(z);
    v.DOB+='-';
    v.DOB+=QString::number(y);
    v.DOB+='-';
    v.DOB+=QString::number(x);





    if(!query.exec("select max(Uid) from voter"))
        qDebug()<<query.lastError();

    query.first();
    v.Uid=query.value(0).toInt()+1;

    v.insert_voter();

    QString S;
    S="Registration Successful\n";
    S+="Your UID is ";
    S+=QString::number(v.Uid);
    S+="\nKindly keep this safe for future references";
    QMessageBox::information(this,"SUCCESSFULL",S);

    hide();

    first_window *jt;
    jt=new first_window(this);
    jt->showFullScreen();

    //qDebug()<<query.lastError();
}

void voter_form::on_cancel_clicked()
{
    hide();
    first_window *jt;
    jt=new first_window(this);
    jt->showFullScreen();
}
