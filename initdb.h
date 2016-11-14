#ifndef INITDB_H
#define INITDB_H
#include <QtSql>
#include <QSqlQuery>
#include <QtDebug>
class myDatabase
{
public:
void mydb()
{

    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );

    db.setDatabaseName( "project.db" );

    if( !db.open() )
    {

      qDebug( "Failed to connect." );
    }
}
};
#endif // INITDB_H
