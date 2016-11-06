#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <QApplication>
class candidate
{
public:
     int Cid;
    QString name;
    QString party;
    QString sex;
    QString DOB;
    int areacode;
    void insert_candidate();
};
extern candidate Ctemp;
#endif // CANDIDATE_H
