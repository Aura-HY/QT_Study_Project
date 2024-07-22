#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化
    picId = 2;
    QPixmap pix("C:\\qt项目\\图标\\1.jpg");
    ui->label->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    //this指的是MainWindow,而MainWindow继承于QWidget，而QWiget又继承于QObject,所以可以直接调用函数
    myTimerId = this->startTimer(1000);//开启一个定时器，时间为1秒钟,返回定时器的编号
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    //有多个定时器区分id
    if(event->timerId()!=myTimerId)
        return;
    QString path("C:\\qt项目\\图标\\");
    path += QString::number(picId);//转化为字符串
    path += ".jpg";

    QPixmap pix(path);
    ui->label->setPixmap(pix);

    picId++;
    if(picId==6){
        picId=1;
    }
}

void MainWindow::on_stopButton_clicked()
{
    this->killTimer(myTimerId);
}

