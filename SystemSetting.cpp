#include "SystemSetting.h"
#include "ui_SystemSetting.h"
#include <QDebug>
#include <QString>
#include <QKeyEvent>


CSystemSetting::CSystemSetting(QWidget *parent): QWidget(parent), ui(new Ui::SystemSetting)
{
    ui->setupUi(this);

    ui->navTipconfigLable->hide();

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnWidth(0, 150); //0 设置列宽
    ui->tableWidget->setColumnWidth(1, 330); //1 设置列宽
    ui->tableWidget->setStyleSheet("selection-background-color:rgb(255,209,128)");
    ui->tableWidget->selectRow(0); // 默认选中第一行
}

CSystemSetting::~CSystemSetting()
{
    delete  ui;
}

void CSystemSetting::init()
{

}

void CSystemSetting::pre()
{
    ui->tableWidget ->setFocus();
}

void CSystemSetting::keyPressEvent(QKeyEvent *ev)
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
