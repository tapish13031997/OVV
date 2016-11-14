

#include <QApplication>
#include "voter.h"
#include "initdb.h"
#include "QMessageBox"
#include "QDate"
#include "voter_form.h"
voter v;
void voter::insert_voter(int flag)
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
   {
       QMessageBox inform;
       inform.critical(0,"ERROR","CONTACT ADMIN");
   }
    query.clear();
    if(flag)
    {
        query.prepare("update area set population = population +1 where areacode = :val ");
        query.bindValue(":val",areacode);
        if(!query.exec())
        {

            QMessageBox inform;
            inform.critical(0,"ERROR","CONTACT ADMIN");
        }
    }

}
