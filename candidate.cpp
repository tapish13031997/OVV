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

    query.prepare("insert into vote values(:val1,0)");
    query.bindValue(":val1",Cid);

    query.exec();

    query.prepare("insert into candidate_vote values(:val1,:val2,0)");
    query.bindValue(":val1",Cid);
    query.bindValue(":val2",areacode);

    query.exec();

}
