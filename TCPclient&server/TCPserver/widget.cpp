#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    server = new QTcpServer;

    server->listen(QHostAddress::AnyIPv4,2266);

    //客户端发起连接，server发出信号
    connect(server,&QTcpServer::newConnection,this,&Widget::newClientHandler);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::newClientHandler()
{
    QTcpSocket *socket = server->nextPendingConnection();

    ui->IPlineEdit->setText(socket->peerAddress().toString());
    ui->portLineEdit->setText(QString::number(socket->peerPort()));

 //   //服务器接受客户端发送的消息
 //   connect(socket,&QTcpSocket::readyRead,this,&Widget::clientInfoSlot);

    //启动线程
    mythread *t = new mythread(socket);

    //触发mythread中的run函数
    t->start();//在线程中接收客户端发送的消息，然后发出信号并传递消息

    //线程接收到消息后，发出信号并传递接收到的消息，触发自定义的槽函数在ui中显示接收到的消息
    connect(t,&mythread::sendToWidget,this,&Widget::threadSlot);
}

void Widget::clientInfoSlot()
{
    // //获取信号的发出者
    // QTcpSocket *s = (QTcpSocket *)sender();
    // ui->receiveLineEdit->setText(QString(s->readAll()));
}

void Widget::threadSlot(QByteArray b)
{
    ui->receiveLineEdit->setText(QString(b));
}
