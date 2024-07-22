#include "widget.h"
#include "./ui_widget.h"

#include<QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //连接数据库
    //要下载mysql驱动，将dll文件复制到qt安装目录`plugins\sqldrivers`目录下
    db = QSqlDatabase::addDatabase("QMYSQL"); //加载MySQL数据库驱动

    db.setDatabaseName("qr_code");
    db.setHostName("47.236.98.161");
    db.setPort(2266);
    db.setUserName("qr_code");
    db.setPassword("jMr8w4Wrs5AfGeX7");

    if(db.open())
    {
        QMessageBox::information(this,"连接提示","连接成功");
    }
    else
    {
        QMessageBox::information(this,"连接提示","连接失败");
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_addButton_clicked()
{
    QString id = ui->numberLineEdit->text();
    QString name = ui->nameLineEdit->text();

    QString sql = QString("insert into student values (%1,'%2');").arg(id).arg(name);

    QSqlQuery query;
    if(query.exec(sql))
    {
        QMessageBox::information(this,"插入提示","插入成功");
    }
    else
    {
        QMessageBox::information(this,"插入提示","插入失败");
    }
}


void Widget::on_selectButton_clicked()
{
    //创建数据库ui对象
    sqltableview *sqlview = new sqltableview(&db);
    sqlview->show();
}

