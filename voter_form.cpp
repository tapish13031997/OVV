#include "voter_form.h"
#include "ui_voter_form.h"
#include "voter.h"
#include "initdb.h"
#include "first_window.h"
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

    v.name=ui->name->text();
    v.username=ui->username->text();
    v.password=ui->password->text();
    QString repassword=ui->repassword->text();

    if(ui->Male->isChecked())
        v.sex="M";
    else
        v.sex="F";

    QString temp;
    temp=ui->area->currentText();

    QSqlQuery query;
    query.prepare("select areacode from area where areaname =:val");
    query.bindValue(":val",temp);

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

    qDebug()<<query.lastError();



    query.exec("select max(Uid) from voter");
    v.Uid=query.value(0).toInt();

    hide();
    it=new voter_window;
    it->showMaximized();

    qDebug()<<query.lastError();
}

void voter_form::on_cancel_clicked()
{
    hide();
    first_window *jt;
    jt=new first_window(this);
    jt->showMaximized();
}
