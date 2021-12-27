#include "currency.h"
#include "ui_currency.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

huobi::huobi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::huobi)
{
    ui->setupUi(this);

    QNetworkAccessManager* m_manager = new QNetworkAccessManager;
    QNetworkRequest request; request.setUrl(QUrl(QString("http://121.37.239.127:25562/Cash")));
    m_manager->get(request);//向网页发起get请求
    connect(m_manager, SIGNAL(finished(QNetworkReply*)), this,SLOT(dealMsg(QNetworkReply*)));//请求完成,获取数据并在槽函数中进行处理


}

void huobi::dealMsg(QNetworkReply * reply)//对数据进行解析
{
    QByteArray array = reply->readAll();
    QJsonParseError error;
    QJsonDocument data = QJsonDocument::fromJson(array, &error);
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    if (!data.isNull()) {
      QJsonArray list = data.array();
      for (int var = 0; var < list.size(); ++var) {
          QJsonValue value = list.at(var);
          QJsonObject obj = value.toObject();
          QString res1 = obj.take("name").toString();
          QString res2 = obj.take("value").toString();
          ui->comboBox->addItem(res1,res2);
          ui->comboBox_2->addItem(res1,res2);
      }
    }
    reply->deleteLater();
}

double huobi::calc() {
    double val = ui->comboBox->currentData().toString().toDouble();
    double a1 = ui->doubleSpinBox->value();

    a1 = a1/val;

    double val2 = ui->comboBox_2->currentData().toString().toDouble();

    a1 = a1*val2;

    ui->label_3->setText("1 中国人民币（CNY） = " + ui->comboBox->currentData().toString() + " " + ui->comboBox->currentText());
    ui->label_4->setText("1 中国人民币（CNY） = " + ui->comboBox_2->currentData().toString() + " " + ui->comboBox_2->currentText());

    return a1;
}

huobi::~huobi()
{
    delete ui;
}




void huobi::on_doubleSpinBox_valueChanged(const QString &arg1)
{
    ui->doubleSpinBox_2->setValue(calc());
}

void huobi::on_comboBox_currentIndexChanged(int index)
{
    ui->doubleSpinBox_2->setValue(calc());
}

void huobi::on_comboBox_2_currentIndexChanged(int index)
{
    ui->doubleSpinBox_2->setValue(calc());
}
