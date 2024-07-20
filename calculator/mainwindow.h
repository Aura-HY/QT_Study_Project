#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QString>
#include<QIcon>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Button1_clicked();

    void on_Button2_clicked();

    void on_Button3_clicked();

    void on_Button4_clicked();

    void on_Button5_clicked();

    void on_Button6_clicked();

    void on_Button7_clicked();

    void on_Button8_clicked();

    void on_Button9_clicked();

    void on_jiaButton_clicked();

    void on_jianButton_clicked();

    void on_chenButton_clicked();

    void on_chuButton_clicked();

    void on_zuoButton_clicked();

    void on_Button_clicked();

    void on_youButton_clicked();

    void on_pushButton_20_clicked();

    void on_gui0Button_clicked();

    void on_dengButton_clicked();

private:
    Ui::MainWindow *ui;
    QString expression;
};
#endif // MAINWINDOW_H
