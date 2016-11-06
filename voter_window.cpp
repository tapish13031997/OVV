#include "voter_window.h"
#include "ui_voter_window.h"
#include "initdb.h"
#include "QMessageBox"
#include "voter_welcome_window.h"
#include "QStringList"
#include "login_window.h"
#include "voter.h"

int Uid;
voter_window::voter_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::voter_window)
{
    ui->setupUi(this);
    ui->username->setText(name);

    QSqlQuery query,query2;

    QSqlQuery query3;

    query3.exec("select areaname from area");



    while(query3.next())
    {
           QString temp=query3.value(0).toString();
           ui->area->addItem(temp);
    }


    query.prepare("select * from voter where username = :val ");
    query.bindValue(":val",name);
    if(!query.exec())
    {
            QMessageBox info;
            info.critical(0,"ERROR","CONTACT ADMIN");
    }
    else
    {
            query.first();
            Uid=query.value(0).toInt();
        ui->password->setText(query.value(2).toString());
        ui->repassword->setText(query.value(2).toString());
        ui->name->setText(query.value(3).toString());
        ui->phone->setText(query.value(7).toString());
        if(query.value(5).toString()=="M")
        {
                ui->Male->toggle();
        }
        else
        {
                ui->Female->toggle();
        }
        QString s;
        s=query.value(6).toString();

        QStringList lst = s.split("-");
        int d = lst[0].toInt();
        int m=lst[1].toInt();
        int y=lst[2].toInt();
         QDate a(y,m,d);
               ui->DOB->setDate(a);
query2.prepare("select areaname from area where areacode=:val");
query2.bindValue(":val",query.value(4));
query2.exec();
query2.first();

int index=ui->area->findText(query2.value(0).toString());

ui->area->setCurrentIndex(index);

}

}

voter_window::~voter_window()
{
    delete ui;
}

void voter_window::on_cancel_clicked()
{
hide();
voter_welcome_window * vwwptr;
vwwptr=new voter_welcome_window(this);
vwwptr->showMaximized();
}

void voter_window::on_submit_clicked()
{
    voter v;

    v.Uid=Uid;
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
query2.prepare("select username from voter where username = :val");
query2.bindValue(":val",v.username);
query2.exec();
QDate aaj=QDate::currentDate();
QStringList lst = v.DOB.split("-");
int d = lst[0].toInt();
int m=lst[1].toInt();
 y=lst[2].toInt();
QDate age(y,m,d);
query2.first();
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
   else if(query2.first() and query2.value(0).toString()!=name)
    {
        qDebug()<<query2.first()<<' '<<query2.value(0).toString()<<' '<<name<<endl;
            QMessageBox inform;
            inform.information(this,"ERROR","USERNAME ALREADY IN USE");
            return ;
    }
else
{
    query.clear();
    query.prepare("delete from voter where uid=:val");
    query.bindValue(":val",v.Uid);
    query.exec();
    if(!query.exec())
    {
            QMessageBox info;
            info.critical(0,"ERROR 404","CONTACT ADMIN");
    }
     v.insert_voter();
    QString S;
    S="Registration Successful\n";
    S+="Your UID is ";
    S+=QString::number(v.Uid);
    S+="\nKindly keep this safe for future references";
    QMessageBox::information(this,"SUCCESSFUL",S);



    hide();

    voter_welcome_window *jt;
    jt=new voter_welcome_window(this);
    jt->showMaximized();
}

}
