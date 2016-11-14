#ifndef ADD_CANDIDATE_H
#define ADD_CANDIDATE_H

#include <QDialog>

namespace Ui {
class add_candidate;
}

class add_candidate : public QDialog
{
    Q_OBJECT

public:
    explicit add_candidate(QWidget *parent = 0);
    ~add_candidate();

private slots:
    void on_submit_clicked();

    void on_cancel_clicked();

private:
    Ui::add_candidate *ui;
};

#endif // ADD_CANDIDATE_H
