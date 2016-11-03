#include "manage_candidate.h"
#include "ui_manage_candidate.h"
#include<initdb.h>
#include"area.h"
manage_candidate::manage_candidate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manage_candidate)
{
    ui->setupUi(this);

    setWindowTitle("Manage Candidates");

    QSqlQuery query;
     area A;
    query.exec("select * from candidate where areacode = :val");
            query.bindValue(":val",A.areacode);

    query.exec();

    while(query.next())
    {
            QString temp=query.value(0).toString();
            ui->cid->addItem(temp);

             temp=query.value(1).toString();
            ui->candidate_name->addItem(temp);

             temp=query.value(2).toString();
            ui->candidate_party->addItem(temp);
    }


}

manage_candidate::~manage_candidate()
{
    delete ui;
}
