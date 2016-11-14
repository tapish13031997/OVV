#ifndef VOTER_WINDOW_H
#define VOTER_WINDOW_H

#include <QMainWindow>

namespace Ui {
class voter_window;
}

class voter_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit voter_window(QWidget *parent = 0);
    ~voter_window();

private slots:
    void on_cancel_clicked();

    void on_submit_clicked();

private:
    Ui::voter_window *ui;
};

#endif // VOTER_WINDOW_H
