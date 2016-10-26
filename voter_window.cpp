#include "voter_window.h"
#include "ui_voter_window.h"

voter_window::voter_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::voter_window)
{
    ui->setupUi(this);
}

voter_window::~voter_window()
{
    delete ui;
}
