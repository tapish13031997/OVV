#ifndef VOTER_H
#define VOTER_H

#include <QApplication>
class voter
{
public:
   int Uid;
   QString username;
   QString password;
   QString name;
   int areacode;
   QString sex;
   QString DOB;
   QString phone;

   void insert_voter();

};

#endif // VOTER_H
