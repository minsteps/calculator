#ifndef CURRENCY_H
#define CURRENCY_H

#include <QWidget>
#include <QNetworkReply>

namespace Ui {
class huobi;
}

class huobi : public QWidget
{
    Q_OBJECT

public:
    explicit huobi(QWidget *parent = nullptr);
    ~huobi();

private slots:
    void dealMsg(QNetworkReply * reply);

    void on_doubleSpinBox_valueChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

private:
    Ui::huobi *ui;
    double calc();

};

#endif // CURRENCY_H
