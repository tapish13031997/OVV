#ifndef MANAGE_AREA_H
#define MANAGE_AREA_H

#include <QDialog>

namespace Ui {
class manage_area;
}

class manage_area : public QDialog
{
    Q_OBJECT

public:
    explicit manage_area(QWidget *parent = 0);
    ~manage_area();

private slots:
    void on_insert_area_clicked();

    void on_delete_area_clicked();

    void on_back_clicked();

private:
    Ui::manage_area *ui;
};

#endif // MANAGE_AREA_H
