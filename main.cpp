#include <QApplication>
#include "mainwindow1.h"
#include "initdb.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow1 w;
    w.Show_first_window();
    QSqlQuery query1;
    query1.exec("delete from canvote");
    return a.exec();
}
