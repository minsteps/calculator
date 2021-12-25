#include "capacity.h"
#include "ui_rongliang.h"

rongliang::rongliang(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rongliang)
{
    ui->setupUi(this);
}

rongliang::~rongliang()
{
    delete ui;
}

double rongliang::calc() {
    int index = ui->comboBox->currentIndex();
    double a1 = ui->doubleSpinBox->value();
    if(index == 2) {
        a1=a1*1000;
    } else if(index==3) {
        a1=a1*1000000;
    } else if(index==4) {
        a1=a1*16.38706;
    } else if(index==5) {
        a1=a1*28316.85;
    } else if(index==6) {
        a1=a1*764554.9;
    } else if(index==7) {
        a1=a1*473.1765;
    } else if(index==8) {
        a1=a1*946.3529;
    } else if(index==9) {
        a1=a1*3785.412;
    }

    index = ui->comboBox_2->currentIndex();
    if(index == 2) {
        a1=a1/1000;
    } else if(index==3) {
        a1=a1/1000000;
    } else if(index==4) {
        a1=a1/16.38706;
    } else if(index==5) {
        a1=a1/28316.85;
    } else if(index==6) {
        a1=a1/764554.9;
    } else if(index==7) {
        a1=a1/473.1765;
    } else if(index==8) {
        a1=a1/946.3529;
    } else if(index==9) {
        a1=a1/3785.412;
    }

    return a1;
}

void rongliang::input(QString num)
{
    QString str = QString::number(ui->doubleSpinBox->value(),10,0);
    str = str + num;
    ui->doubleSpinBox->setValue(str.toDouble());

}


void rongliang::on_doubleSpinBox_valueChanged(double arg1)
{
    ui->doubleSpinBox_2->setValue(calc());
}

void rongliang::on_comboBox_activated(const QString &arg1)
{
    ui->doubleSpinBox_2->setValue(calc());
}

void rongliang::on_comboBox_2_activated(const QString &arg1)
{
    ui->doubleSpinBox_2->setValue(calc());
}

void rongliang::on_pushButton_clicked()
{
    input("1");
}

void rongliang::on_pushButton_2_clicked()
{
    input("2");
}

void rongliang::on_pushButton_3_clicked()
{
    input("3");
}

void rongliang::on_pushButton_4_clicked()
{
    input("4");
}

void rongliang::on_pushButton_5_clicked()
{
    input("5");
}

void rongliang::on_pushButton_6_clicked()
{
    input("6");
}

void rongliang::on_pushButton_7_clicked()
{
    input("7");
}

void rongliang::on_pushButton_8_clicked()
{
    input("8");
}

void rongliang::on_pushButton_9_clicked()
{
    input("9");
}

void rongliang::on_pushButton_12_clicked()
{
    input("0");
}

void rongliang::on_pushButton_15_clicked()
{
    ui->doubleSpinBox->setValue(0);
}

void rongliang::on_pushButton_16_clicked()
{
    QString str = QString::number(ui->doubleSpinBox->value(),10,0);
    str=str.mid(0,str.size()-1);
    ui->doubleSpinBox->setValue(str.toDouble());
}
