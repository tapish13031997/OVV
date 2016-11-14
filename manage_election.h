#ifndef MANAGE_ELECTION_H
#define MANAGE_ELECTION_H

#include <QMainWindow>

namespace Ui {
class Manage_Election;
}

class Manage_Election : public QMainWindow
{
    Q_OBJECT

public:
    explicit Manage_Election(QWidget *parent = 0);
    ~Manage_Election();

private slots:
    void on_result_clicked();

    void on_back_clicked();

    void on_abort_clicked();

    void on_stats_clicked();

    void on_save_clicked();

private:
    Ui::Manage_Election *ui;
};

#endif // MANAGE_ELECTION_H
