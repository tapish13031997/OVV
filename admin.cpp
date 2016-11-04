#include "admin.h"
#include "ui_admin.h"
#include "select_area.h"
#include "first_window.h"
#include "manage_candidate.h"
int flag;
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
{
    hide();

    flag=1;

    select_area *it;
    it= new select_area;
    it->showMaximized();

}

void admin::on_commandLinkButton_clicked()
{
    hide();
    first_window *it;
    it=new first_window;
    it->showMaximized();
}
