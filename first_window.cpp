#include "first_window.h"
#include "ui_first_window.h"
#include <login_window.h>
#include <voter_form.h>
first_window::first_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::first_window)
{
    ui->setupUi(this);
}

first_window::~first_window()
{
    delete ui;
}

void first_window::on_login_button_clicked()
{
    login_window * lwptr;
hide();
lwptr =new login_window(this);
lwptr->showMaximized();

}

void first_window::on_register_button_clicked()
{

    voter_form *vfptr;
  hide();
vfptr=new voter_form(this);
vfptr->showMaximized();
}
