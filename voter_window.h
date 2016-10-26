#ifndef VOTER_WINDOW_H
#define VOTER_WINDOW_H

#include <QDialog>

namespace Ui {
class voter_window;
}

class voter_window : public QDialog
{
    Q_OBJECT

public:
    explicit voter_window(QWidget *parent = 0);
    ~voter_window();

private:
    Ui::voter_window *ui;
};

#endif // VOTER_WINDOW_H
