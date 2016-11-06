#include "vote.h"
#include "initdb.h"
vote::vote()
{

}

void vote::insert_vote()
{
    QSqlQuery query;
    query.prepare("update candidate_vote set votecount=votecount+1 where Cid = :val");

    query.bindValue(":val",Cid);

    query.exec();

    query.prepare("update area_vote set votecount=votecount+1 where areacode=:val");

    query.bindValue(":val",areacode);

    query.exec();
}
