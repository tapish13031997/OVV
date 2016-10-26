#ifndef first_window_H
#define first_window_H

#include <QMainWindow>
#include <login_window.h>
namespace Ui {
class first_window;
}

class first_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit first_window(QWidget *parent = 0);
    ~first_window();

private slots:
    void on_login_button_clicked();

private:
    Ui::first_window *ui;
    login_window * lwptr;

};

#endif // first_window_H
