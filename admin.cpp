#include "admin.h"
#include "ui_admin.h"
#include "select_area.h"
#include "first_window.h"
admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

void admin::on_candidates_clicked()
{   hide();
    select_area *it;
    it=new select_area;
    it->showFullScreen();
}

void admin::on_commandLinkButton_clicked()
{
    hide();
    first_window *it;
    it=new first_window;
    it->showMaximized();
}
