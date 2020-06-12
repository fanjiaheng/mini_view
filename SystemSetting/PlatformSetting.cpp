#include "PlatformSetting.h"
#include "ui_PlatformSetting.h"
#include <QDebug>
#include <QKeyEvent>


CPlatformSetting::CPlatformSetting(QWidget *parent): QWidget(parent), ui(new Ui::PlatformSetting)
{
    ui->setupUi(this);
}

CPlatformSetting::~CPlatformSetting()
{
    delete ui;
}

void CPlatformSetting::init()
{

}

void CPlatformSetting::pre()
{
    ui->enable->setFocus();
}

void CPlatformSetting::keyPressEvent(QKeyEvent *ev)
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
