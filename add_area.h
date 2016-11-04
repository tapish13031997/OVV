#ifndef ADD_AREA_H
#define ADD_AREA_H

#include <QDialog>

namespace Ui {
class add_area;
}

class add_area : public QDialog
{
    Q_OBJECT

public:
    explicit add_area(QWidget *parent = 0);
    ~add_area();

private slots:
    void on_submit_clicked();

    void on_back_clicked();

private:
    Ui::add_area *ui;
};

#endif // ADD_AREA_H
