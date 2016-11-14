#ifndef VIEW_STATS_H
#define VIEW_STATS_H

#include <QMainWindow>

namespace Ui {
class view_stats;
}

class view_stats : public QMainWindow
{
    Q_OBJECT

public:
    explicit view_stats(QWidget *parent = 0);
    ~view_stats();

private:
    Ui::view_stats *ui;
};

#endif // VIEW_STATS_H
