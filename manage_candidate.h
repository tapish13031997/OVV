#ifndef MANAGE_CANDIDATE_H
#define MANAGE_CANDIDATE_H

#include <QDialog>

namespace Ui {
class manage_candidate;
}

class manage_candidate : public QDialog
{
    Q_OBJECT

public:
    explicit manage_candidate(QWidget *parent = 0);
    ~manage_candidate();

private:
    Ui::manage_candidate *ui;
};

#endif // MANAGE_CANDIDATE_H
