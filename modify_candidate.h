#ifndef MODIFY_CANDIDATE_H
#define MODIFY_CANDIDATE_H

#include <QDialog>

namespace Ui {
class modify_candidate;
}

class modify_candidate : public QDialog
{
    Q_OBJECT

public:
    explicit modify_candidate(QWidget *parent = 0);
    ~modify_candidate();

private slots:

    void on_modify_clicked();

    void on_cancel_clicked();

private:
    Ui::modify_candidate *ui;
};

#endif // MODIFY_CANDIDATE_H
