#include "DeviceMaintain.h"
#include "ui_DeviceMaintain.h"
#include <QDebug>
#include <QKeyEvent>


CDeviceMaintain::CDeviceMaintain(QWidget *parent): QWidget(parent), ui(new Ui::DeviceMaintain)
{
    ui->setupUi(this);
}

CDeviceMaintain::~CDeviceMaintain()
{
    delete ui;
}

void CDeviceMaintain::init()
{

}

void CDeviceMaintain::pre()
{
    ui->pushButton->setFocus();
}

void CDeviceMaintain::keyPressEvent(QKeyEvent *ev)
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
