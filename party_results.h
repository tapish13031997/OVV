#ifndef PARTY_RESULTS_H
#define PARTY_RESULTS_H

#include <QMainWindow>

namespace Ui {
class party_results;
}

class party_results : public QMainWindow
{
    Q_OBJECT

public:
    explicit party_results(QWidget *parent = 0);
    ~party_results();

private slots:



    void on_pushButton_clicked();

private:
    Ui::party_results *ui;
};

#endif // PARTY_RESULTS_H
