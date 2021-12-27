#include "riqi.h"
#include "ui_riqi.h"

riqi::riqi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::riqi)
{
    ui->setupUi(this);
}

riqi::~riqi()
{
    delete ui;
}

void riqi::on_dateEdit_userDateChanged(const QDate &date)
{
    int cha = DaysBetween2Date(ui->dateEdit->date().toString("yyyy-MM-dd"),ui->dateEdit_2->date().toString("yyyy-MM-dd"));
    if(cha==-1) {
        cha = DaysBetween2Date(ui->dateEdit_2->date().toString("yyyy-MM-dd"),ui->dateEdit->date().toString("yyyy-MM-dd"));
    }
    ui->label->setText( QString::number(cha) + " 天");
}

void riqi::on_dateEdit_2_userDateChanged(const QDate &date)
{
    int cha = DaysBetween2Date(ui->dateEdit->date().toString("yyyy-MM-dd"),ui->dateEdit_2->date().toString("yyyy-MM-dd"));
    if(cha==-1) {
        cha = DaysBetween2Date(ui->dateEdit_2->date().toString("yyyy-MM-dd"),ui->dateEdit->date().toString("yyyy-MM-dd"));
    }
    ui->label->setText( QString::number(cha) + " 天");
}

int riqi::DaysBetween2Date(QString date1, QString date2)                                                                //主调函数
{
                                                                                                                        //取出日期中的年月日
     int year1, month1, day1;
     int year2, month2, day2;
     QString datelast,datenow;
     datelast=date1;
     datenow=date2;
     QRegExp exp("[年月日-:-： ]");
     datelast =datelast.replace(exp,"");
     datenow =datenow.replace(exp,"");
     if(datenow<datelast)
     {
        return -1;
     }
     if(!StringToDate(datelast, year1, month1, day1) || !StringToDate(datenow, year2,month2,day2))                           //调用截取函数
     {
        return -1;
     }
     if(year1 == year2 && month1 == month2)
     {
          return day1 > day2 ? day1 - day2 : day2 - day1;
     }
     else if(year1 == year2)
     {
         int d1, d2;
         d1 = DayInYear(year1, month1, day1);
         d2 = DayInYear(year2, month2, day2);
         return d1 > d2 ? d1 - d2 : d2 - d1;
     }
     else
     {
         if(year1 > year2)
         {
             swap(year1, year2);
             swap(month1, month2);
             swap(day1, day2);
         }
         int d1,d2,d3;
         if(IsLeap(year1))
             d1 = 366 - DayInYear(year1,month1, day1);
         else
             d1 = 365 - DayInYear(year1,month1, day1);
         d2 = DayInYear(year2,month2,day2);
         d3 = 0;
         for(int year = year1 + 1; year < year2; year++)
         {
             if(IsLeap(year))
                 d3 += 366;
             else
                 d3 += 365;
         }
         return d1 + d2 + d3;
     }
}
bool riqi::IsLeap(int year)
{
   return (year % 4 ==0 || year % 400 ==0) && (year % 100 !=0);
}
bool riqi::StringToDate(QString date ,int& year, int& month, int& day)            //数据解析
{
    year = date.mid(0,4).toInt();                                                   //数据截取
    month = date.mid(4,2).toInt();                                                  //数据截取
    day = date.mid(6,2).toInt();                                                    //数据截取

    int DAY[12]={31,28,31,30,31,30,31,31,30,31,30,31};                              //初始化12个月份的数据
    if(IsLeap(year))                                                                //如果是闰年，那么将2月的数据更新为29天
    {
         DAY[1] = 29;
    }
    return year >= 0 && month<=12 && month>0 && day<=DAY[month-1] && day>0;
}
int riqi::DayInYear(int year, int month, int day)
{
    int DAY[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(IsLeap(year))
        DAY[1] = 29;
    for(int i=0; i<month - 1; ++i)
    {
        day += DAY[i];
    }
    return day;
}
void riqi::swap(int a,int b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}


void riqi::on_dateEdit_3_userDateChanged(const QDate &date)
{
    int year = ui->spinBox->value();
    int month = ui->spinBox_2->value();
    int day = ui->spinBox_3->value();
    QDate da = ui->dateEdit_3->date();

    if(ui->radioButton->isChecked()) {
        da = da.addYears(year);
        da = da.addMonths(month);
        da = da.addDays(day);
    } else {
        da = da.addYears(-year);
        da = da.addMonths(-month);
        da = da.addDays(-day);
    }
    ui->label_15->setText(da.toString());
}

void riqi::on_spinBox_valueChanged(int arg1)
{
    int year = ui->spinBox->value();
    int month = ui->spinBox_2->value();
    int day = ui->spinBox_3->value();
    QDate da = ui->dateEdit_3->date();

    if(ui->radioButton->isChecked()) {
        da = da.addYears(year);
        da = da.addMonths(month);
        da = da.addDays(day);
    } else {
        da = da.addYears(-year);
        da = da.addMonths(-month);
        da = da.addDays(-day);
    }
    ui->label_15->setText(da.toString());
}

void riqi::on_spinBox_2_valueChanged(int arg1)
{
    int year = ui->spinBox->value();
    int month = ui->spinBox_2->value();
    int day = ui->spinBox_3->value();
    QDate da = ui->dateEdit_3->date();

    if(ui->radioButton->isChecked()) {
        da = da.addYears(year);
        da = da.addMonths(month);
        da = da.addDays(day);
    } else {
        da = da.addYears(-year);
        da = da.addMonths(-month);
        da = da.addDays(-day);
    }
    ui->label_15->setText(da.toString());
}

void riqi::on_spinBox_3_valueChanged(int arg1)
{
    int year = ui->spinBox->value();
    int month = ui->spinBox_2->value();
    int day = ui->spinBox_3->value();
    QDate da = ui->dateEdit_3->date();

    if(ui->radioButton->isChecked()) {
        da = da.addYears(year);
        da = da.addMonths(month);
        da = da.addDays(day);
    } else {
        da = da.addYears(-year);
        da = da.addMonths(-month);
        da = da.addDays(-day);
    }
    ui->label_15->setText(da.toString());
}

void riqi::on_radioButton_clicked()
{
    int year = ui->spinBox->value();
    int month = ui->spinBox_2->value();
    int day = ui->spinBox_3->value();
    QDate da = ui->dateEdit_3->date();

    if(ui->radioButton->isChecked()) {
        da = da.addYears(year);
        da = da.addMonths(month);
        da = da.addDays(day);
    } else {
        da = da.addYears(-year);
        da = da.addMonths(-month);
        da = da.addDays(-day);
    }
    ui->label_15->setText(da.toString());
}

void riqi::on_radioButton_2_clicked()
{
    int year = ui->spinBox->value();
    int month = ui->spinBox_2->value();
    int day = ui->spinBox_3->value();
    QDate da = ui->dateEdit_3->date();

    if(ui->radioButton->isChecked()) {
        da = da.addYears(year);
        da = da.addMonths(month);
        da = da.addDays(day);
    } else {
        da = da.addYears(-year);
        da = da.addMonths(-month);
        da = da.addDays(-day);
    }
    ui->label_15->setText(da.toString());
}
