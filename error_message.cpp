#include "error_message.h"
#include "ui_error_message.h"

error_message::error_message(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::error_message)
{
    ui->setupUi(this);
}

error_message::~error_message()
{
    delete ui;
}
