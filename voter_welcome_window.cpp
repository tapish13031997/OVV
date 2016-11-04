#include "voter_welcome_window.h"
#include "ui_voter_welcome_window.h"
#include "login_window.h"
#include "voter_window.h"
voter_welcome_window::voter_welcome_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::voter_welcome_window)
{
    ui->setupUi(this);
    ui->lineEdit->setText(name);
}

voter_welcome_window::~voter_welcome_window()
{
    delete ui;
}

void voter_welcome_window::on_commandLinkButton_clicked()
{
       hide();
    login_window *lwptr;
    lwptr=new login_window(this);
    lwptr->showMaximized();
}

void voter_welcome_window::on_pushButton_clicked()
{
    hide();
        voter_window *vw;
        vw=new voter_window(this);
        vw->showMaximized();
}
