#include "ui_voter_form.h"
#include "first_window.h"
voter_form::voter_form(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::voter_form)
{
    ui->setupUi(this);
}

voter_form::~voter_form()
{
    delete ui;
}

void voter_form::on_pushButton_2_clicked()          //cancel push button
{

    first_window * fwptr;
    fwptr=new first_window(this);
        hide();
        fwptr->showMaximized();
}

void voter_form::on_pushButton_clicked()        //submit button
{
first_window * fwptr;
fwptr=new first_window(this);
    hide();
    fwptr->showMaximized();
}
