#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money{0};
    void changeMoney(int diff);
    void updateButtonState();

private slots:
    void on_bb10_clicked();

    void on_bb50_clicked();

    void on_bb100_clicked();

    void on_bb500_clicked();

    void on_PBCoffee_clicked();

    void on_PBtea_clicked();

    void on_PBmilk_clicked();

    void on_pbRest_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
