#include "admin.h"
#include "ui_admin.h"
#include "select_area.h"
#include "first_window.h"
#include "manage_candidate.h"
#include "manage_voter.h"
#include "manage_parties.h"
#include "manage_area.h"
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

//void admin::on_candidates_clicked()
//{  // hide();
   // select_area *it;
  //  it=new select_area;
 //   it->showFullScreen();
//}

void admin::on_commandLinkButton_clicked()
{
    hide();
    first_window *it;
    it=new first_window;
    it->showMaximized();
}

void admin::on_voters_clicked()
{
    hide();

       flag=2;

       select_area *it;
       it= new select_area;
       it->showMaximized();
}

void admin::on_candidates_clicked()
{
    hide();

       flag=1;

       select_area *it;
       it= new select_area;
       it->showMaximized();


}

void admin::on_areas_2_clicked()
{
    hide();
        manage_parties *mpptr;
        mpptr=new manage_parties(this);
        mpptr->showFullScreen();

}

void admin::on_areas_clicked()
{
    hide();
        manage_area *maptr;
        maptr=new manage_area(this);
maptr->showFullScreen();
}
