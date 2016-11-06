#include "voter_form.h"
#include "ui_voter_form.h"
#include "voter.h"
#include "initdb.h"
#include "first_window.h"
#include "QMessageBox"
#include "voter_window.h"
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
    QSqlQuery query2;
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
    if(ui->area->currentText().isEmpty())
    {
        QMessageBox inform;
        inform.critical(this,"ERROR-510","Select Area !");
        return ;

    }
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

    v.DOB+=QString::number(x);
    v.DOB+='-';
    v.DOB+=QString::number(y);
    v.DOB+='-';
    v.DOB+=QString::number(z);
query2.prepare("select * from voter where username = :val");
query2.bindValue(":val",v.username);
query2.exec();
QDate aaj=QDate::currentDate();
QStringList lst = v.DOB.split("-");
int d = lst[0].toInt();
int m=lst[1].toInt();
 y=lst[2].toInt();
QDate age(y,m,d);
if(v.name.isEmpty())
{
    QMessageBox inform;
    inform.critical(this,"ERROR-500","Name field can not be empty");
    return ;
}
else if(v.username.isEmpty())
{

    QMessageBox inform;
    inform.critical(this,"ERROR-500","Username field can not be empty");
    return ;

}
else if(v.password.isEmpty())
{

    QMessageBox inform;
    inform.critical(this,"ERROR-500","Password field can not be empty");
    return ;

}
else if(v.phone.isEmpty())
{

    QMessageBox inform;
    inform.critical(this,"ERROR-500","Phone Number MUST be provided");
    return ;
}
else if(aaj.year()-age.year()<18 or (age.year()==aaj.year()+18 and age.month()>aaj.month()) or (age.year()==aaj.year()+18 and age.month()==aaj.month() and age.day()>aaj.day()) ) {
    QMessageBox inform;
    inform.critical(this,"ERROR-500","You must be 18 or above to become a voter");
    return ;
}

   else if(query2.first())
    {

            QMessageBox inform;
            inform.information(this,"ERROR","USERNAME ALREADY IN USE");
            return ;
    }
    else
    {
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
        QMessageBox::information(this,"SUCCESSFUL",S);

        hide();

        first_window *jt;
        jt=new first_window(this);
        jt->showMaximized();
    }

}

void voter_form::on_cancel_clicked()
{
    hide();
    first_window *jt;
    jt=new first_window(this);
    jt->showMaximized();
}
void voter_form::myvoter_edit(QString name)
{

    QSqlQuery query2;
    query2.prepare("delete from voter where username =:val");
    query2.bindValue(":val",name);
    query2.exec();
    vfptr=new voter_form(this);
vfptr->showMaximized();

}
