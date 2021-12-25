#ifndef RIQI_H
#define RIQI_H

#include <QWidget>

namespace Ui {
class riqi;
}

class riqi : public QWidget
{
    Q_OBJECT

public:
    explicit riqi(QWidget *parent = nullptr);
    ~riqi();

private slots:
    void on_dateEdit_userDateChanged(const QDate &date);

    void on_dateEdit_2_userDateChanged(const QDate &date);

    void on_dateEdit_3_userDateChanged(const QDate &date);

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::riqi *ui;

    bool IsLeap(int year);
    bool StringToDate(QString date ,int& year, int& month, int& day);
    int DayInYear(int year, int month, int day);
    int DaysBetween2Date(QString date1, QString date2);
    void swap(int a,int b);
};

#endif // RIQI_H
