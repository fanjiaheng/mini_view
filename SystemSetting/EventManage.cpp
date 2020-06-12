#include "EventManage.h"
#include "ui_EventManage.h"
#include <QDebug>
#include <QKeyEvent>


CEventManage::CEventManage(QWidget *parent): QWidget(parent), ui(new Ui::EventManage)
{
    ui->setupUi(this);
}

CEventManage::~CEventManage()
{
    delete ui;
}

void CEventManage::init()
{

}

void CEventManage::pre()
{
    ui->radioButton->setFocus();
}

void CEventManage::keyPressEvent(QKeyEvent *ev)
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
