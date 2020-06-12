#include "DeviceManage.h"
#include "ui_DeviceManage.h"
#include <QDebug>
#include <QKeyEvent>


CDeviceManage::CDeviceManage(QWidget *parent): QWidget(parent), ui(new Ui::DeviceManage)
{
    ui->setupUi(this);
}

CDeviceManage::~CDeviceManage()
{
    delete ui;
}

void CDeviceManage::init()
{

}

void CDeviceManage::pre()
{
    ui->label->setFocus();
}

void CDeviceManage::keyPressEvent(QKeyEvent *ev)
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

    return;
}
