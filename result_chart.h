     #ifndef RESULT_CHART_H
    #define RESULT_CHART_H

    #include <QWidget>

    namespace Ui {
    class result_chart;
    }

    class result_chart : public QWidget
    {
        Q_OBJECT

    public:
        explicit result_chart(QWidget *parent = 0);
        ~result_chart();
        void paintEvent(QPaintEvent *);

    private:
        Ui::result_chart *ui;
    };

    #endif // RESULT_CHART_H
