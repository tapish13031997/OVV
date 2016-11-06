#ifndef VIEW_CANDIDATES_H
#define VIEW_CANDIDATES_H

#include <QMainWindow>

namespace Ui {
class view_candidates;
}

class view_candidates : public QMainWindow
{
    Q_OBJECT

public:
    explicit view_candidates(QWidget *parent = 0);
    ~view_candidates();

private slots:
    void on_commandLinkButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::view_candidates *ui;
};

#endif // VIEW_CANDIDATES_H
