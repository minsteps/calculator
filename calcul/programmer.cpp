#include "programmer.h"
#include "ui_programmer.h"
#include <math.h>

chengxuyuan::chengxuyuan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chengxuyuan)
{
    ui->setupUi(this);
    ui->pushButton_15->setEnabled(false);
    ui->pushButton_24->setEnabled(false);

    ui->pushButton_25->setEnabled(false);
    ui->pushButton_23->setEnabled(false);
    ui->pushButton_26->setEnabled(false);
    ui->pushButton_19->setEnabled(false);
    ui->pushButton_20->setEnabled(false);
    ui->pushButton_21->setEnabled(false);
}

chengxuyuan::~chengxuyuan()
{
    delete ui;
}

void chengxuyuan::input(QString num)
{
    str=str + num;
    if(isFinish) {
        ui->textBrowser_2->setText(ui->textBrowser->document()->toPlainText());
        isFinish = false;
    }
    ui->textBrowser->setText(str);
    int num2 = 0;
    bool ok;

    if(ui->radioButton->isChecked()) {
        num2 = ui->textBrowser->document()->toPlainText().toInt(&ok,16);
    } else if(ui->radioButton_2->isChecked()) {
        num2 = ui->textBrowser->document()->toPlainText().toInt(&ok,10);
    } else if(ui->radioButton_3->isChecked()) {
        num2 = ui->textBrowser->document()->toPlainText().toInt(&ok,8);
    } else if(ui->radioButton_4->isChecked()) {
        num2 = ui->textBrowser->document()->toPlainText().toInt(&ok,2);
    }
    ui->radioButton->setText("HEX " + QString("%1").arg(num2, 4, 16, QLatin1Char('0')));
    ui->radioButton_2->setText("DEC " + QString::number(num2));
    ui->radioButton_3->setText("OCT " + QString::number(num2, 8));
    ui->radioButton_4->setText("BIN " + QString::number(num2, 2));
}

void chengxuyuan::shuangMu(QString fuhao)
{
    if(ui->textBrowser_2->document()->toPlainText()=="") {
        ui->textBrowser_2->setText(ui->radioButton_2->text().replace(0,4,"") + fuhao);
        ui->textBrowser->setText("");
        str = "";
    } else {
        QString stra;
        QString shang = ui->textBrowser_2->document()->toPlainText();
        str = ui->radioButton_2->text().replace(0,4,"");

        if(str=="") {
            shang.replace(shang.length()-1,1,fuhao);
            ui->textBrowser_2->setText(shang);
        } else if(shang.contains(">>",Qt::CaseInsensitive)) {
            shang = shang.replace(">>","");
            int a1 = shang.toInt();
            int a2 = str.toInt();
            a1 = a1 >> a2;
            stra = QString::number(a1);
            ui->textBrowser_2->setText(stra + fuhao);
        } else if(shang.contains("<<",Qt::CaseInsensitive)) {
            shang = shang.replace("<<","");
            int a1 = shang.toInt();
            int a2 = str.toInt();
            a1 = a1 << a2;
            stra = QString::number(a1);
            ui->textBrowser_2->setText(stra + fuhao);
        } else if(shang.contains("&",Qt::CaseInsensitive)) {
            shang = shang.replace("&","");
            int a1 = shang.toInt();
            int a2 = str.toInt();
            a1 = a1 & a2;
            stra = QString::number(a1);
            ui->textBrowser_2->setText(stra + fuhao);
        } else if(shang.contains("|",Qt::CaseInsensitive)) {
            shang = shang.replace("|","");
            int a1 = shang.toInt();
            int a2 = str.toInt();
            a1 = a1 | a2;
            stra = QString::number(a1);
            ui->textBrowser_2->setText(stra + fuhao);
        } else {
            ui->textBrowser_2->setText(shang + str);
            QScriptEngine scriptEngin;
            QScriptValue scripVal = scriptEngin.evaluate(ui->textBrowser_2->document()->toPlainText()).toString();
            stra = scripVal.toString();
            ui->textBrowser_2->setText(stra + fuhao);
        }

        ui->textBrowser->setText("");
        str = "";

        int num2 = 0;
        bool ok;

        if(ui->radioButton->isChecked()) {
            num2 = ui->textBrowser_2->document()->toPlainText().toInt(&ok,16);
        } else if(ui->radioButton_2->isChecked()) {
            num2 = ui->textBrowser_2->document()->toPlainText().toInt(&ok,10);
        } else if(ui->radioButton_3->isChecked()) {
            num2 = ui->textBrowser_2->document()->toPlainText().toInt(&ok,8);
        } else if(ui->radioButton_4->isChecked()) {
            num2 = ui->textBrowser_2->document()->toPlainText().toInt(&ok,2);
        }
        ui->radioButton->setText("HEX " + QString("%1").arg(num2, 4, 16, QLatin1Char('0')));
        ui->radioButton_2->setText("DEC " + QString::number(num2));
        ui->radioButton_3->setText("OCT " + QString::number(num2, 8));
        ui->radioButton_4->setText("BIN " + QString::number(num2, 2));
    }
}

void chengxuyuan::on_pushButton_clicked()
{
    input("1");
}

void chengxuyuan::on_pushButton_2_clicked()
{
    input("2");
}

void chengxuyuan::on_pushButton_3_clicked()
{
    input("3");
}

void chengxuyuan::on_pushButton_4_clicked()
{
    input("4");
}

void chengxuyuan::on_pushButton_5_clicked()
{
    input("5");
}

void chengxuyuan::on_pushButton_6_clicked()
{
    input("6");
}

void chengxuyuan::on_pushButton_7_clicked()
{
    input("7");
}

void chengxuyuan::on_pushButton_8_clicked()
{
    input("8");
}

void chengxuyuan::on_pushButton_9_clicked()
{
    input("9");
}

void chengxuyuan::on_pushButton_12_clicked()
{
    input("0");
}

void chengxuyuan::on_pushButton_10_clicked()
{
    shuangMu("+");
}

void chengxuyuan::on_pushButton_11_clicked()
{
    shuangMu("-");
}

void chengxuyuan::on_pushButton_13_clicked()
{
    shuangMu("*");
}

void chengxuyuan::on_pushButton_14_clicked()
{
    shuangMu("/");
}

void chengxuyuan::on_pushButton_15_clicked()
{
}

void chengxuyuan::on_pushButton_16_clicked()
{
    str=str.mid(0,str.size()-1);
    ui->textBrowser->setText(str);

    int num2 = 0;
    bool ok;

    if(ui->radioButton->isChecked()) {
        num2 = ui->textBrowser->document()->toPlainText().toInt(&ok,16);
    } else if(ui->radioButton_2->isChecked()) {
        num2 = ui->textBrowser->document()->toPlainText().toInt(&ok,10);
    } else if(ui->radioButton_3->isChecked()) {
        num2 = ui->textBrowser->document()->toPlainText().toInt(&ok,8);
    } else if(ui->radioButton_4->isChecked()) {
        num2 = ui->textBrowser->document()->toPlainText().toInt(&ok,2);
    }
    ui->radioButton->setText("HEX " + QString("%1").arg(num2, 4, 16, QLatin1Char('0')));
    ui->radioButton_2->setText("DEC " + QString::number(num2));
    ui->radioButton_3->setText("OCT " + QString::number(num2, 8));
    ui->radioButton_4->setText("BIN " + QString::number(num2, 2));
}

void chengxuyuan::on_pushButton_17_clicked()
{
    str="";
    ui->textBrowser->setText(str);
    ui->textBrowser_2->setText("");
}

void chengxuyuan::on_pushButton_18_clicked()
{
    str = ui->radioButton_2->text().replace(0,4,"");
    if(ui->textBrowser_2->document()->toPlainText()=="") {
        ui->textBrowser_2->setText(str);
        ui->textBrowser->setText("");
        str = "";
        isFinish = true;
    } else {
        QString stra;
        QString shang = ui->textBrowser_2->document()->toPlainText();
        if(shang.contains(">>",Qt::CaseInsensitive)) {
            shang = shang.replace(">>","");
            int a1 = shang.toInt();
            int a2 = str.toInt();
            a1 = a1 >> a2;
            stra = QString::number(a1);
        } else if(shang.contains("<<",Qt::CaseInsensitive)) {
            shang = shang.replace("<<","");
            int a1 = shang.toInt();
            int a2 = str.toInt();
            a1 = a1 << a2;
            stra = QString::number(a1);
        } else if(shang.contains("&",Qt::CaseInsensitive)) {
            shang = shang.replace("&","");
            int a1 = shang.toInt();
            int a2 = str.toInt();
            a1 = a1 & a2;
            stra = QString::number(a1);
        } else if(shang.contains("|",Qt::CaseInsensitive)) {
            shang = shang.replace("|","");
            int a1 = shang.toInt();
            int a2 = str.toInt();
            a1 = a1 | a2;
            stra = QString::number(a1);
        } else {
            ui->textBrowser_2->setText(ui->textBrowser_2->document()->toPlainText() + str);
            QScriptEngine scriptEngin;
            QScriptValue scripVal = scriptEngin.evaluate(ui->textBrowser_2->document()->toPlainText()).toString();
            stra = scripVal.toString();
        }
        ui->textBrowser_2->setText(stra);
        ui->textBrowser->setText("");
        str = "";
        isFinish = true;
    }

    int num2 = 0;
    bool ok;

    if(ui->radioButton->isChecked()) {
        num2 = ui->textBrowser_2->document()->toPlainText().toInt(&ok,16);
    } else if(ui->radioButton_2->isChecked()) {
        num2 = ui->textBrowser_2->document()->toPlainText().toInt(&ok,10);
    } else if(ui->radioButton_3->isChecked()) {
        num2 = ui->textBrowser_2->document()->toPlainText().toInt(&ok,8);
    } else if(ui->radioButton_4->isChecked()) {
        num2 = ui->textBrowser_2->document()->toPlainText().toInt(&ok,2);
    }
    ui->radioButton->setText("HEX " + QString("%1").arg(num2, 4, 16, QLatin1Char('0')));
    ui->radioButton_2->setText("DEC " + QString::number(num2));
    ui->radioButton_3->setText("OCT " + QString::number(num2, 8));
    ui->radioButton_4->setText("BIN " + QString::number(num2, 2));
}

void chengxuyuan::on_pushButton_22_clicked()
{
    shuangMu("%");
}

void chengxuyuan::on_pushButton_24_clicked()
{

}

void chengxuyuan::on_pushButton_25_clicked()
{
    input("E");
}

void chengxuyuan::on_pushButton_23_clicked()
{
    input("D");
}

void chengxuyuan::on_pushButton_26_clicked()
{
    input("F");
}

void chengxuyuan::on_pushButton_27_clicked()
{
    shuangMu("<<");
}
void chengxuyuan::on_pushButton_19_clicked()
{
    input("A");
}

void chengxuyuan::on_pushButton_20_clicked()
{
    input("B");
}

void chengxuyuan::on_pushButton_21_clicked()
{
    input("C");
}

void chengxuyuan::on_radioButton_clicked()
{
    str = ui->radioButton->text().replace(0,4,"");
    ui->textBrowser->setText(str);


    ui->pushButton_25->setEnabled(true);
    ui->pushButton_23->setEnabled(true);
    ui->pushButton_26->setEnabled(true);
    ui->pushButton_19->setEnabled(true);
    ui->pushButton_20->setEnabled(true);
    ui->pushButton_21->setEnabled(true);

    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_9->setEnabled(true);
    ui->pushButton_10->setEnabled(true);
    ui->pushButton_12->setEnabled(true);
}

void chengxuyuan::on_radioButton_3_clicked()
{
    str = ui->radioButton_3->text().replace(0,4,"");
    ui->textBrowser->setText(str);

    ui->pushButton_25->setEnabled(false);
    ui->pushButton_23->setEnabled(false);
    ui->pushButton_26->setEnabled(false);
    ui->pushButton_19->setEnabled(false);
    ui->pushButton_20->setEnabled(false);
    ui->pushButton_21->setEnabled(false);

    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_10->setEnabled(true);
    ui->pushButton_12->setEnabled(true);
}

void chengxuyuan::on_radioButton_2_clicked()
{
    str = ui->radioButton_2->text().replace(0,4,"");
    ui->textBrowser->setText(str);

    ui->pushButton_25->setEnabled(false);
    ui->pushButton_23->setEnabled(false);
    ui->pushButton_26->setEnabled(false);
    ui->pushButton_19->setEnabled(false);
    ui->pushButton_20->setEnabled(false);
    ui->pushButton_21->setEnabled(false);

    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_9->setEnabled(true);
    ui->pushButton_10->setEnabled(true);
    ui->pushButton_12->setEnabled(true);
}

void chengxuyuan::on_radioButton_4_clicked()
{
    str = ui->radioButton_4->text().replace(0,4,"");
    ui->textBrowser->setText(str);

    ui->pushButton_25->setEnabled(false);
    ui->pushButton_23->setEnabled(false);
    ui->pushButton_26->setEnabled(false);
    ui->pushButton_19->setEnabled(false);
    ui->pushButton_20->setEnabled(false);
    ui->pushButton_21->setEnabled(false);

    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
    ui->pushButton_12->setEnabled(true);
}

void chengxuyuan::on_pushButton_29_clicked()
{
    shuangMu("&");
}

void chengxuyuan::on_pushButton_28_clicked()
{
    shuangMu(">>");
}

void chengxuyuan::on_pushButton_30_clicked()
{
    shuangMu("|");
}
