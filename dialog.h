#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    void myset(const QString &kname);
    ~Dialog();

private slots:


private:
    Ui::Dialog *ui;
    Dialog * naya;
};

#endif // DIALOG_H
