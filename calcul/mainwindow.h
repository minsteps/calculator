#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtScript/QScriptEngine>
#include "standard.h"
#include "science.h"
#include "riqi.h"
#include "capacity.h"
#include "currency.h"
#include "programmer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

    biaozhun *biaozhunView;
    kexue *kexueView;
};

#endif // MAINWINDOW_H
