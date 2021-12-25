#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());

    ui->tabWidget->addTab(new biaozhun, tr("标准"));
    ui->tabWidget->addTab(new kexue, tr("科学"));
    ui->tabWidget->addTab(new chengxuyuan,tr("程序员"));
    ui->tabWidget->addTab(new riqi(),tr("日期"));
    ui->tabWidget->addTab(new rongliang,tr("容量"));
    ui->tabWidget->addTab(new huobi,tr("货币"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

