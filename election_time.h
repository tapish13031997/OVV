#ifndef ELECTION_TIME_H
#define ELECTION_TIME_H

#include <QDateTime>
class election_time{

public:
    QDateTime samay=QDateTime(QDate(2016,11,6),QTime(20,0,0));
};
extern election_time start_time;
extern election_time end_time;

#endif // ELECTION_TIME_H

