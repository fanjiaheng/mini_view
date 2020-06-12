#include "SystemInfo.h"
#include "ui_SystemInfo.h"
#include <QDebug>
#include <QKeyEvent>


CSystemInfo::CSystemInfo(QWidget *parent): QWidget(parent), ui(new Ui::SystemInfo)
{
    ui->setupUi(this);
}

CSystemInfo::~CSystemInfo()
{
    delete ui;
}

void CSystemInfo::init()
{

}

void CSystemInfo::pre()
{
    ui->softVersionVal->setFocus();
}

void CSystemInfo::keyPressEvent(QKeyEvent *ev)
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

    if(ev->key() == Qt::Key_Up)
    {
        return;
    }

    if(ev->key() == Qt::Key_Down)
    {
        return;
    }


    return;
}
