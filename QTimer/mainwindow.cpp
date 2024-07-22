#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer;
    picId = 2;

    QImage img;
    img.load("C:\\qt项目\\图标\\1.jpg");
    ui->label->setPixmap(QPixmap::fromImage(img));

    //定时器时间到，发出timeout信号
    connect(timer,&QTimer::timeout,this,&MainWindow::timeoutSlots);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    timer->start(1000);
}

void MainWindow::timeoutSlots()
{
    QString path("C:\\qt项目\\图标\\");
    path += QString::number(picId);
    path += ".jpg";

    QImage img;
    img.load(path);
    ui->label->setPixmap(QPixmap::fromImage(img));

    picId++;
    if(picId==6){
        picId=1;
    }
}
void MainWindow::on_pushButton_2_clicked()
{
    timer->stop();
}


void MainWindow::on_pushButton_3_clicked()
{
    //只跳一张图片
    QTimer::singleShot(1000,this,SLOT(timeoutSlots()));
}

