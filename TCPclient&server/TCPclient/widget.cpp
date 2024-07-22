#include "widget.h"
#include "./ui_widget.h"

#include<QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //初始化前要在类文件里先设置
    socket = new QTcpSocket; //创建socket对象
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_cancelButton_clicked()
{
    this->close();
}


void Widget::on_connectButton_clicked()
{
    //获取输入框的信息
    QString IP = ui->addressLineEdit->text();
    QString port = ui->portLineEdit->text();

    //连接服务器 具体参数要求要看文档
    socket->connectToHost(QHostAddress(IP),port.toShort());

    //连接服务器成功，socket对象会发出信号
    connect(socket,&QTcpSocket::connected,[this]()
    {
        QMessageBox::information(this,"连接消息","连接服务器成功");

        this->hide();
        chat *c = new chat(socket);
        c->show();
    });

    //连接失败
    connect(socket,&QTcpSocket::disconnected,[this](){
        QMessageBox::warning(this,"连接消息","连接异常，网络断开");
    });
}

