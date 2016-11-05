#include "vote.h"
#include "initdb.h"
vote::vote()
{

}

void vote::insert_vote()
{
    QSqlQuery query;
    query.prepare("update vote set votecount=votecount+1 where Cid = :val");

    query.bindValue(":val",Cid);

    query.exec();
}
