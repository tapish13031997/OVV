

#include <QApplication>
#include "voter.h"
#include "initdb.h"

void voter::insert_voter()
{


   QSqlQuery query;

   query.prepare("insert into voter values(:Uid,:username,:password,:name,:areacode,:sex,:date,:phone)");


   query.bindValue(":Uid",Uid);
   query.bindValue(":username",username);
   query.bindValue(":password",password);
   query.bindValue(":name",name);
   query.bindValue(":areacode",areacode);
   query.bindValue(":sex",sex);
   query.bindValue(":date",DOB);
   query.bindValue(":phone",phone);

   if(!query.exec())
   qDebug()<<query.lastError();



}
