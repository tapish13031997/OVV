#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <QApplication>
class candidate
{
public:
    QString name;
    QString party;
    QString sex;
    QString DOB;
    int areacode;
    int Cid;
    void insert_candidate();
};

#endif // CANDIDATE_H
