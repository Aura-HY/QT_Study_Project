#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //连接信号与槽 谁发出信号，发出什么信号，谁处理信号，怎么处理信号
    //写法1
    connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(on_pushButton_clicked()));
    //写法2
    //错误1：槽函数后面不用加（） 错误2:取地址的地址名是函数名如：MainWindow
    connect(ui->cancelButton, &QPushButton::clicked,this, &MainWindow::on_cancelButton_clicked);
    //写法3,用在槽函数的内容较少的情况
    //弹出消息框，要include
    connect(ui->browseButton,&QPushButton::clicked,[this]()
    {
        QMessageBox::information(this,"信息","点击浏览");
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //获取lineedit数据
    QString program = ui->lineEdit->text();//没有提示可以直接打对象的名字
    //创建process对象
    QProcess *myProcess = new QProcess(this);
    myProcess->start(program);
}


void MainWindow::on_cancelButton_clicked()
{
    this->close();
}

