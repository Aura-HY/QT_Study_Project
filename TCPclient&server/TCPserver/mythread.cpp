#include "mythread.h"

mythread::mythread(QTcpSocket *s)
{
    socket = s;
}

void mythread::run()
{
    connect(socket,&QTcpSocket::readyRead,this,&mythread::clienInfoSlot);
}

void mythread::clienInfoSlot()
{
    //自定义信号
    emit sendToWidget(socket->readAll());
}
