#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QSqlDatabase>
#include<QString>
#include<QSqlQuery>
#include "sqltableview.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_addButton_clicked();

    void on_selectButton_clicked();

private:
    Ui::Widget *ui;
    QSqlDatabase db;
    sqltableview *sqlui;
};
#endif // WIDGET_H
