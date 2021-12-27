#include "science.h"
#include "ui_science.h"
#include <math.h>
#include <QtCore/qmath.h>

kexue::kexue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kexue)
{
    ui->setupUi(this);
}

kexue::~kexue()
{
    delete ui;
}

void kexue::input(QString num)
{
    if(isFinish) {
        str=str + num;
        ui->textBrowser_2->setText(ui->textBrowser->document()->toPlainText());
        ui->textBrowser->setText(str);
        isFinish = false;
    } else {
        str=str + num;
        ui->textBrowser->setText(str);
    }
}

void kexue::shuangMu(QString fuhao)
{
    if(ui->textBrowser_2->document()->toPlainText()=="") {
        ui->textBrowser_2->setText(str + fuhao);
        ui->textBrowser->setText("");
        str = "";
    } else {
        QString stra;
        QString shang = ui->textBrowser_2->document()->toPlainText();
        ui->textBrowser_2->setText(shang + str);
        if(str=="") {
            shang.replace(shang.length()-1,1,fuhao);
            ui->textBrowser_2->setText(shang);
        } else {
            QScriptEngine scriptEngin;
            QScriptValue scripVal = scriptEngin.evaluate(ui->textBrowser_2->document()->toPlainText()).toString();
            stra = scripVal.toString();
            ui->textBrowser_2->setText(stra + fuhao);
        }

        ui->textBrowser->setText("");
        str = "";
    }
}

void kexue::on_pushButton_clicked()
{
    input("1");
}

void kexue::on_pushButton_2_clicked()
{
    input("2");
}

void kexue::on_pushButton_3_clicked()
{
    input("3");
}

void kexue::on_pushButton_4_clicked()
{
    input("4");
}

void kexue::on_pushButton_5_clicked()
{
    input("5");
}

void kexue::on_pushButton_6_clicked()
{
    input("6");
}

void kexue::on_pushButton_7_clicked()
{
    input("7");
}

void kexue::on_pushButton_8_clicked()
{
    input("8");
}

void kexue::on_pushButton_9_clicked()
{
    input("9");
}

void kexue::on_pushButton_12_clicked()
{
    input("0");
}

void kexue::on_pushButton_10_clicked()
{
    shuangMu("+");
}

void kexue::on_pushButton_11_clicked()
{
    shuangMu("-");
}

void kexue::on_pushButton_13_clicked()
{
    shuangMu("*");
}

void kexue::on_pushButton_14_clicked()
{
    shuangMu("/");
}

void kexue::on_pushButton_15_clicked()
{
    input(".");
}

void kexue::on_pushButton_16_clicked()
{
    str=str.mid(0,str.size()-1);
    ui->textBrowser->setText(str);
}

void kexue::on_pushButton_17_clicked()
{
    str="";
    ui->textBrowser->setText(str);
    ui->textBrowser_2->setText("");
}

void kexue::on_pushButton_18_clicked()
{
    if(ui->textBrowser_2->document()->toPlainText()=="") {
        ui->textBrowser_2->setText(str);
        ui->textBrowser->setText("");
        str = "";
        isFinish = true;
    } else {
        ui->textBrowser_2->setText(ui->textBrowser_2->document()->toPlainText() + str);
        QScriptEngine scriptEngin;
        QScriptValue scripVal = scriptEngin.evaluate(ui->textBrowser_2->document()->toPlainText()).toString();
        QString stra = scripVal.toString();
        ui->textBrowser_2->setText(stra);
        ui->textBrowser->setText("");
        str = "";
        isFinish = true;
    }
}

void kexue::on_textBrowser_textChanged()
{
    //str = ui->textBrowser->document()->toPlainText();
}

void kexue::on_pushButton_22_clicked()
{
    shuangMu("%");
}

void kexue::on_pushButton_24_clicked()
{
    if(str.startsWith("+",Qt::CaseInsensitive)) {
        str.replace(0,1,"-");
    } else if(str.startsWith("-",Qt::CaseInsensitive)) {
        str.replace(0,1,"+");
    } else {
        str = "-" + str;
    }
    ui->textBrowser->setText(str);
}

void kexue::on_pushButton_25_clicked()
{
    if(ui->textBrowser->document()->toPlainText()!="") {
        double num = ui->textBrowser->document()->toPlainText().toDouble();
        num = qTan(num);
        ui->textBrowser->setText(QString::number(num));
        str = QString::number(num);
    } else if(ui->textBrowser_2->document()->toPlainText()!="") {
        str = ui->textBrowser_2->document()->toPlainText();
        if(str.endsWith("+",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("-",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("*",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("/",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("^",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        }
        ui->textBrowser_2->setText(str);
        str= "";
        QScriptEngine scriptEngin;
        QScriptValue scripVal = scriptEngin.evaluate(ui->textBrowser_2->document()->toPlainText()).toString();
        QString stra = scripVal.toString();
        double num = stra.toDouble();
        num = qTan(num);
        ui->textBrowser_2->setText(QString::number(num));
    }
}

void kexue::on_pushButton_23_clicked()
{
    if(ui->textBrowser->document()->toPlainText()!="") {
        double num = ui->textBrowser->document()->toPlainText().toDouble();
        num = 1 / num;
        ui->textBrowser->setText(QString::number(num));
        str = QString::number(num);
    } else if(ui->textBrowser_2->document()->toPlainText()!="") {
        str = ui->textBrowser_2->document()->toPlainText();
        if(str.endsWith("+",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("-",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("*",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("/",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("^",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        }
        ui->textBrowser_2->setText(str);
        str= "";
        QScriptEngine scriptEngin;
        QScriptValue scripVal = scriptEngin.evaluate(ui->textBrowser_2->document()->toPlainText()).toString();
        QString stra = scripVal.toString();
        double num = stra.toDouble();
        num = 1 / num;
        ui->textBrowser_2->setText(QString::number(num));
    }
}

void kexue::on_pushButton_26_clicked()
{
    if(ui->textBrowser->document()->toPlainText()!="") {
        double num = ui->textBrowser->document()->toPlainText().toDouble();
        num = num* num;
        ui->textBrowser->setText(QString::number(num));
        str = QString::number(num);
    } else if(ui->textBrowser_2->document()->toPlainText()!="") {
        str = ui->textBrowser_2->document()->toPlainText();
        if(str.endsWith("+",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("-",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("*",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("/",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("^",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        }
        ui->textBrowser_2->setText(str);
        str= "";
        QScriptEngine scriptEngin;
        QScriptValue scripVal = scriptEngin.evaluate(ui->textBrowser_2->document()->toPlainText()).toString();
        QString stra = scripVal.toString();
        double num = stra.toDouble();
        num = num* num;
        ui->textBrowser_2->setText(QString::number(num));
    }
}

void kexue::on_pushButton_27_clicked()
{
    if(ui->textBrowser->document()->toPlainText()!="") {
        double num = ui->textBrowser->document()->toPlainText().toDouble();
        num = sqrt(num);
        ui->textBrowser->setText(QString::number(num));
        str = QString::number(num);
    } else if(ui->textBrowser_2->document()->toPlainText()!="") {
        str = ui->textBrowser_2->document()->toPlainText();
        if(str.endsWith("+",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("-",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("*",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("/",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("^",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        }
        ui->textBrowser_2->setText(str);
        str= "";
        QScriptEngine scriptEngin;
        QScriptValue scripVal = scriptEngin.evaluate(ui->textBrowser_2->document()->toPlainText()).toString();
        QString stra = scripVal.toString();
        double num = stra.toDouble();
        num = sqrt(num);
        ui->textBrowser_2->setText(QString::number(num));
    }
}

void kexue::on_pushButton_29_clicked()
{
    if(ui->textBrowser->document()->toPlainText()!="") {
        double num = ui->textBrowser->document()->toPlainText().toDouble();
        num = log(num);
        ui->textBrowser->setText(QString::number(num));
        str = QString::number(num);
    } else if(ui->textBrowser_2->document()->toPlainText()!="") {
        str = ui->textBrowser_2->document()->toPlainText();
        if(str.endsWith("+",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("-",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("*",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("/",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("^",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        }
        ui->textBrowser_2->setText(str);
        str= "";
        QScriptEngine scriptEngin;
        QScriptValue scripVal = scriptEngin.evaluate(ui->textBrowser_2->document()->toPlainText()).toString();
        QString stra = scripVal.toString();
        double num = stra.toDouble();
        num = log(num);
        ui->textBrowser_2->setText(QString::number(num));
    }
}

void kexue::on_pushButton_30_clicked()
{
    if(ui->textBrowser->document()->toPlainText()!="") {
        double num = ui->textBrowser->document()->toPlainText().toDouble();
        num = qPow(10,num);
        ui->textBrowser->setText(QString::number(num));
        str = QString::number(num);
    } else if(ui->textBrowser_2->document()->toPlainText()!="") {
        str = ui->textBrowser_2->document()->toPlainText();
        if(str.endsWith("+",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("-",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("*",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("/",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("^",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        }
        ui->textBrowser_2->setText(str);
        str= "";
        QScriptEngine scriptEngin;
        QScriptValue scripVal = scriptEngin.evaluate(ui->textBrowser_2->document()->toPlainText()).toString();
        QString stra = scripVal.toString();
        double num = stra.toDouble();
        num = qPow(10,num);
        ui->textBrowser_2->setText(QString::number(num));
    }
}

void kexue::on_pushButton_36_clicked()
{
    input("3.1415926");
}

void kexue::on_pushButton_37_clicked()
{
    input("2.7182818");
}

void kexue::on_pushButton_34_clicked()
{
    if(ui->textBrowser->document()->toPlainText()!="") {
        double num = ui->textBrowser->document()->toPlainText().toDouble();
        num = qAbs(num);
        ui->textBrowser->setText(QString::number(num));
        str = QString::number(num);
    } else if(ui->textBrowser_2->document()->toPlainText()!="") {
        str = ui->textBrowser_2->document()->toPlainText();
        if(str.endsWith("+",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("-",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("*",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("/",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("^",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        }
        ui->textBrowser_2->setText(str);
        str= "";
        QScriptEngine scriptEngin;
        QScriptValue scripVal = scriptEngin.evaluate(ui->textBrowser_2->document()->toPlainText()).toString();
        QString stra = scripVal.toString();
        double num = stra.toDouble();
        num = qAbs(num);
        ui->textBrowser_2->setText(QString::number(num));
    }
}

void kexue::on_pushButton_38_clicked()
{
    if(ui->textBrowser->document()->toPlainText()!="") {
        double num = ui->textBrowser->document()->toPlainText().toDouble();
        num = qExp(num);
        ui->textBrowser->setText(QString::number(num));
        str = QString::number(num);
    } else if(ui->textBrowser_2->document()->toPlainText()!="") {
        str = ui->textBrowser_2->document()->toPlainText();
        if(str.endsWith("+",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("-",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("*",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("/",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("^",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        }
        ui->textBrowser_2->setText(str);
        str= "";
        QScriptEngine scriptEngin;
        QScriptValue scripVal = scriptEngin.evaluate(ui->textBrowser_2->document()->toPlainText()).toString();
        QString stra = scripVal.toString();
        double num = stra.toDouble();
        num = qExp(num);
        ui->textBrowser_2->setText(QString::number(num));
    }
}

void kexue::on_pushButton_39_clicked()
{
    shuangMu("%");
}

void kexue::on_pushButton_31_clicked()
{
    if(ui->textBrowser->document()->toPlainText()!="") {
        double num = ui->textBrowser->document()->toPlainText().toDouble();
        num = qSin(num);
        ui->textBrowser->setText(QString::number(num));
        str = QString::number(num);
    } else if(ui->textBrowser_2->document()->toPlainText()!="") {
        str = ui->textBrowser_2->document()->toPlainText();
        if(str.endsWith("+",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("-",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("*",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("/",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("^",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        }
        ui->textBrowser_2->setText(str);
        str= "";
        QScriptEngine scriptEngin;
        QScriptValue scripVal = scriptEngin.evaluate(ui->textBrowser_2->document()->toPlainText()).toString();
        QString stra = scripVal.toString();
        double num = stra.toDouble();
        num = qSin(num);
        ui->textBrowser_2->setText(QString::number(num));
    }
}

void kexue::on_pushButton_32_clicked()
{
    if(ui->textBrowser->document()->toPlainText()!="") {
        double num = ui->textBrowser->document()->toPlainText().toDouble();
        num = qCos(num);
        ui->textBrowser->setText(QString::number(num));
        str = QString::number(num);
    } else if(ui->textBrowser_2->document()->toPlainText()!="") {
        str = ui->textBrowser_2->document()->toPlainText();
        if(str.endsWith("+",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("-",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("*",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("/",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("^",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        }
        ui->textBrowser_2->setText(str);
        str= "";
        QScriptEngine scriptEngin;
        QScriptValue scripVal = scriptEngin.evaluate(ui->textBrowser_2->document()->toPlainText()).toString();
        QString stra = scripVal.toString();
        double num = stra.toDouble();
        num = qCos(num);
        ui->textBrowser_2->setText(QString::number(num));
    }
}

void kexue::on_pushButton_33_clicked()
{
    if(ui->textBrowser->document()->toPlainText()!="") {
        double num = ui->textBrowser->document()->toPlainText().toDouble();
        num = qLn(num)/qLn(10);
        ui->textBrowser->setText(QString::number(num));
        str = QString::number(num);
    } else if(ui->textBrowser_2->document()->toPlainText()!="") {
        str = ui->textBrowser_2->document()->toPlainText();
        if(str.endsWith("+",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("-",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("*",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("/",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("^",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        }
        ui->textBrowser_2->setText(str);
        str= "";
        QScriptEngine scriptEngin;
        QScriptValue scripVal = scriptEngin.evaluate(ui->textBrowser_2->document()->toPlainText()).toString();
        QString stra = scripVal.toString();
        double num = stra.toDouble();
        num = qLn(num)/qLn(10);
        ui->textBrowser_2->setText(QString::number(num));
    }
}

void kexue::on_pushButton_35_clicked()
{
    if(ui->textBrowser->document()->toPlainText()!="") {
        double num = ui->textBrowser->document()->toPlainText().toDouble();
        num = qPow(2.7182818284590452353602874713527,num);
        ui->textBrowser->setText(QString::number(num));
        str = QString::number(num);
    } else if(ui->textBrowser_2->document()->toPlainText()!="") {
        str = ui->textBrowser_2->document()->toPlainText();
        if(str.endsWith("+",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("-",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("*",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("/",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("^",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        }
        ui->textBrowser_2->setText(str);
        str= "";
        QScriptEngine scriptEngin;
        QScriptValue scripVal = scriptEngin.evaluate(ui->textBrowser_2->document()->toPlainText()).toString();
        QString stra = scripVal.toString();
        double num = stra.toDouble();
        num = qPow(2.7182818284590452353602874713527,num);
        ui->textBrowser_2->setText(QString::number(num));
    }
}

void kexue::on_pushButton_28_clicked()
{
    if(ui->textBrowser->document()->toPlainText()!="") {
        double num = ui->textBrowser->document()->toPlainText().toDouble();
        num = qLn(num);
        ui->textBrowser->setText(QString::number(num));
        str = QString::number(num);
    } else if(ui->textBrowser_2->document()->toPlainText()!="") {
        str = ui->textBrowser_2->document()->toPlainText();
        if(str.endsWith("+",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("-",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("*",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("/",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        } else if(str.endsWith("^",Qt::CaseInsensitive)) {
            str.replace(str.length()-1,1,"");
        }
        ui->textBrowser_2->setText(str);
        str= "";
        QScriptEngine scriptEngin;
        QScriptValue scripVal = scriptEngin.evaluate(ui->textBrowser_2->document()->toPlainText()).toString();
        QString stra = scripVal.toString();
        double num = stra.toDouble();
        num = qLn(num);
        ui->textBrowser_2->setText(QString::number(num));
    }
}
