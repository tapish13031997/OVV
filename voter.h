#ifndef VOTER_H
#define VOTER_H

#include <QApplication>
class voter
{
public:
   int Uid;//0
   QString username;//1
   QString password;//2
   QString name;//3
   int areacode;//4
   QString sex;//5
   QString DOB;//6
   QString phone;//7

   void insert_voter(int flag);

};
extern voter v,temp;
extern int flag;
#endif // VOTER_H

