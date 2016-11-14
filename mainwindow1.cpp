#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include "voter.h"
#include "initdb.h"
#include "first_window.h"
MainWindow1::MainWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{
    ui->setupUi(this);
    myDatabase killer;
    killer.mydb();
}

MainWindow1::~MainWindow1()
{
    delete ui;
}

void MainWindow1 :: Show_first_window()
{
        first_window *fwptr;
    fwptr = new first_window(this);
    fwptr->showMaximized();
}
