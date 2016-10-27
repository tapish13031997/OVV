#include <QApplication>
#include "mainwindow1.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow1 w;
    w.Show_first_window();
    return a.exec();
}
