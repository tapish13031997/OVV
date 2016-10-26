#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H

#include <QMainWindow>
#include <dialog.h>
#include <first_window.h>

namespace Ui {
class MainWindow1;
}

class MainWindow1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow1(QWidget *parent = 0);
    void Show_first_window();
    ~MainWindow1();

private slots:
private:
    Ui::MainWindow1 *ui;
    first_window *fwptr;

};

#endif // MAINWINDOW1_H
