#ifndef SELECT_AREA_H
#define SELECT_AREA_H

#include <QDialog>


namespace Ui {
class select_area;
}

class select_area : public QDialog
{
    Q_OBJECT

public:
    explicit select_area(QWidget *parent = 0);
    ~select_area();

private slots:
    void on_next_clicked();

    void on_cancel_clicked();

private:
    Ui::select_area *ui;
};

#endif // SELECT_AREA_H
