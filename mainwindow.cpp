#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(fun()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fun()
{
    QTime time = QTime ::currentTime();
    int hour=time.hour();
    if(hour>=12) {ui->label_ampm->setText("PM");if(hour>12)hour=hour-12;}
    else ui->label_ampm->setText("AM");
    int min=time.minute();
    int sec=time.second();
    QString hs= hour<10?"0"+QString::number(hour):QString::number(hour);
    QString ms= min<10?"0"+QString::number(min):QString::number(min);
    ui->label_time_h->setText(hs);
    ui->label_time_m->setText(ms);
    if(sec&1)ui->label_time_c->setText(":");
    else ui->label_time_c->setText(" ");
}

