#ifndef ERROR_MESSAGE_H
#define ERROR_MESSAGE_H

#include <QDialog>

namespace Ui {
class error_message;
}

class error_message : public QDialog
{
    Q_OBJECT

public:
    explicit error_message(QWidget *parent = 0);
    ~error_message();

private:
    Ui::error_message *ui;
};

#endif // ERROR_MESSAGE_H
