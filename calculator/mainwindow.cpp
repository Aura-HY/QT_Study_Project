#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include"Calculate.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //固定窗口大小，不能拉动
    this->setMaximumSize(320,420);
    this->setMinimumSize(320,420);
    //设置窗口名字
    this->setWindowTitle("计算机");

    QFont f("仿宋",13);//字体对象
    ui->lineEdit->setFont(f);

    //按钮上放图片
    QIcon con("C:\\qt项目\\图标\\删除");
    ui->pushButton_20->setIcon(con);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button1_clicked()
{
    expression += "1";
    ui->lineEdit -> setText(expression);
}

void MainWindow::on_Button2_clicked()
{
    expression += "2";
    ui->lineEdit -> setText(expression);
}


void MainWindow::on_Button3_clicked()
{
    expression += "3";
    ui->lineEdit -> setText(expression);
}



void MainWindow::on_Button4_clicked()
{
    expression += "4";
    ui->lineEdit -> setText(expression);
}


void MainWindow::on_Button5_clicked()
{
    expression += "5";
    ui->lineEdit -> setText(expression);
}


void MainWindow::on_Button6_clicked()
{
    expression += "6";
    ui->lineEdit -> setText(expression);
}


void MainWindow::on_Button7_clicked()
{
    expression += "7";
    ui->lineEdit -> setText(expression);
}


void MainWindow::on_Button8_clicked()
{
    expression += "8";
    ui->lineEdit -> setText(expression);
}


void MainWindow::on_Button9_clicked()
{
    expression += "9";
    ui->lineEdit -> setText(expression);
}


void MainWindow::on_jiaButton_clicked()
{
    expression += "+";
    ui->lineEdit -> setText(expression);
}


void MainWindow::on_jianButton_clicked()
{
    expression += "-";
    ui->lineEdit -> setText(expression);
}


void MainWindow::on_chenButton_clicked()
{
    expression += "*";
    ui->lineEdit -> setText(expression);
}


void MainWindow::on_chuButton_clicked()
{
    expression += "/";
    ui->lineEdit -> setText(expression);
}


void MainWindow::on_zuoButton_clicked()
{
    expression += "(";
    ui->lineEdit -> setText(expression);
}


void MainWindow::on_Button_clicked()
{
    expression += "0";
    ui->lineEdit -> setText(expression);
}


void MainWindow::on_youButton_clicked()
{
    expression += ")";
    ui->lineEdit -> setText(expression);
}


void MainWindow::on_pushButton_20_clicked()
{
    expression.chop(1);
    ui->lineEdit->setText(expression);
}


void MainWindow::on_gui0Button_clicked()
{
    expression.clear();
    ui->lineEdit->clear();
}


void MainWindow::on_dengButton_clicked()
{
    QString res = Calculate::calculate(expression);
    ui->lineEdit->setText(res);
    expression = res;
}

