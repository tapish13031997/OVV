#include "voter_form.h"
#include "ui_voter_form.h"

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
