#ifndef AREA_H
#define AREA_H
#include <QApplication>

class area
{
    public:
    long long Uid;
        QString username;
        QString password;
        QString name[1000];
        QString address[1000];
        QString sex;
        QString DOB;
        long long phone;
        void insert_area(area &B);
};

#endif // AREA_H
