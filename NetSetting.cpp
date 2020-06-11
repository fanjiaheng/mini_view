#include "NetSetting.h"
#include "ui_NetSetting.h"
#include <QDebug>
#include <QString>
#include <QKeyEvent>


CNetSetting::CNetSetting(QWidget *parent): QWidget(parent), ui(new Ui::NetSetting)
{
    ui->setupUi(this);

    ui->navTipconfigLable->hide();

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnWidth(0, 150); //0 设置列宽
    ui->tableWidget->setColumnWidth(1, 330); //1 设置列宽
    ui->tableWidget->setStyleSheet("selection-background-color:rgb(255,209,128)");
    ui->tableWidget->selectRow(0); // 默认选中第一行s
}

CNetSetting::~CNetSetting()
{
    delete ui;
}

void CNetSetting::init()
{

}

void CNetSetting::pre()
{
    ui->tableWidget ->setFocus();
}

void CNetSetting::keyPressEvent(QKeyEvent *ev)
{
    if(ui->tableWidget->hasFocus())
    {
        if(ev->key() == Qt::Key_Return)
        {
            return;
        }

        if(ev->key() == Qt::Key_Escape)
        {
            QWidget::keyPressEvent(ev);
            return;
        }
    }
    else
    {
        if(ev->key() == Qt::Key_Return)
        {
            return;
        }

        if(ev->key() == Qt::Key_Escape)
        {
            QWidget::keyPressEvent(ev);
            return;
        }
    }

    return;
}
