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
  //  qDebug()<<v.Uid<<' '<<v.username<<' '<<v.password<<' '<<v.phone<<' '<<v.name<<endl;

    QString S;
    S="Registration Successful\n";
    S+="Your UID is ";
    S+=QString::number(v.Uid);
    S+="\nKindly keep this safe for future references";
    QMessageBox::information(this,"SUCCESSFULL",S);

    hide();

    first_window *jt;
    jt=new first_window(this);
    jt->showMaximized();

    //qDebug()<<query.lastError();
}

void voter_form::on_cancel_clicked()
{
    hide();
    first_window *jt;
    jt=new first_window(this);
    jt->showMaximized();
}
void voter_form::voter_edit(int uid)
{
    QSqlQuery query,query2;

    query.prepare("select * from voter where uid =:val");
    query.bindValue(":val",uid);
if(!query.exec())
{
       QMessageBox::information(this,"UNSUCCESSFULL","");
}
query.first();
ui->username->setText(query.value(1).toString());
ui->password->setText(query.value(2).toString());
ui->name->setText(query.value(3).toString());
ui->repassword->setText(query.value(2).toString());
ui->password->setEchoMode(QLineEdit::Normal);
ui->repassword->setEchoMode(QLineEdit::Normal);
//ui->DOB;
ui->phone->setText(query.value(7).toString());
ui->username->setText(query.value(1).toString());
        query2.prepare("select areaname from area where areacode =:val");
        query2.bindValue(":val",query.value(4).toInt());
        query2.exec();
        query2.first();
        ui->area->setCurrentText(query2.value(0).toString());

query2.clear();
query2.prepare("delete from voter where uid =:val");
query2.bindValue(":val",uid);
}
