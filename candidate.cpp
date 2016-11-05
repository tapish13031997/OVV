#include "candidate.h"
#include "initdb.h"
void candidate::insert_candidate()
{
    QSqlQuery query;

    query.prepare("insert into candidate values (:Cid,:name,:party,:sex,:dob,:areacode)");

    query.bindValue(":Cid",Cid);

    query.bindValue(":name",name);

    query.bindValue(":party",party);

    query.bindValue(":sex",sex);

    query.bindValue(":dob",DOB);

    query.bindValue(":areacode",areacode);

    query.exec();

    qDebug()<<query.lastError();
}
