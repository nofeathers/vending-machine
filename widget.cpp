#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);

    updateButtonState();
}

Widget::~Widget() {
    delete ui;
}
void Widget::changeMoney(int diff) {
    money += diff;
    ui->lcdNumber->display(money);
    updateButtonState();

}

void Widget::updateButtonState() {
    ui->PBCoffee->setEnabled(money >= 100);
    ui->PBmilk->setEnabled(money >= 200);
    ui->PBtea->setEnabled(money >= 150);
    ui->pbRest->setEnabled(money > 0);
}

void Widget::on_bb10_clicked() {
    changeMoney(10);
}


void Widget::on_bb50_clicked() {
    changeMoney(50);
}

void Widget::on_bb100_clicked() {
    changeMoney(100);
}


void Widget::on_bb500_clicked() {
    changeMoney(500);
}


void Widget::on_PBCoffee_clicked() {
    changeMoney(-100);

}


void Widget::on_PBtea_clicked() {
    changeMoney(-150);
}


void Widget::on_PBmilk_clicked() {
    changeMoney(-200);

}

void Widget::on_pbRest_clicked() {
    int coins[] = {500, 100, 50, 10};
    int result[4] = {0};
    QString mge;
    QMessageBox mb;

    for(int i = 0; i < 4; i++) {
        result[i] = money / coins[i];
        money %= coins[i];
    }

    for(int i = 0; i < 4; i++) {
        mge += QString::number(coins[i]) + "won: " + QString::number(result[i]) + ", ";

    }

    mb.information(this, "coin Reset", mge);
    ui->lcdNumber->display(money);
    updateButtonState();
}

