#include "VideoSetting.h"
#include "ui_VideoSetting.h"
#include <QDebug>
#include <QString>
#include <QKeyEvent>


CVideoSetting::CVideoSetting(QWidget *parent): QWidget(parent), ui(new Ui::VideoSetting)
{
    ui->setupUi(this);

    ui->navTipconfigLable->hide();

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnWidth(0, 150); //0 设置列宽
    ui->tableWidget->setColumnWidth(1, 330); //1 设置列宽
    ui->tableWidget->setStyleSheet("selection-background-color:rgb(255,209,128)");
    ui->tableWidget->selectRow(0); // 默认选中第一行

    m_listWidget = new QListWidget(this);
    m_listWidget->setFixedSize(240,260);
    m_listWidget->move(240, 50);
    m_listWidget->hide();

    connect(this, SIGNAL(signalShowResolutionList()), this, SLOT(slotShowResolutionList()));
    connect(this, SIGNAL(signalShowVideoCodeList()), this, SLOT(slotShowVideoCodeList()));
    connect(this, SIGNAL(signalSetResolution(QString)), this, SLOT(slotSetResolution(QString)));
    connect(this, SIGNAL(signalSetVideoCode(QString)), this, SLOT(slotSetVideoCode(QString)));
}

CVideoSetting::~CVideoSetting()
{

}

void CVideoSetting::init()
{
    qDebug("视频设置 - 获取分辨率 和 视频编码.");
}

void CVideoSetting::pre()
{
    ui->tableWidget ->setFocus();
//    ui->tableWidget->selectRow(0); // 默认选中第一行
}

void CVideoSetting::slotShowResolutionList()
{
    m_listWidget->setFocus();

    new QListWidgetItem(tr("1280*760 30P"), m_listWidget);
    new QListWidgetItem(tr("1280*760 60P"), m_listWidget);
    new QListWidgetItem(tr("1920*1080 30P"), m_listWidget);
    new QListWidgetItem(tr("1920*1080 60P"), m_listWidget);

    ui->navTipconfigLable->setText("视频分辨率");
    ui->navTipconfigLable->show();

    auto index = 0;
    if(m_resolution == "1280*760 30P")
    {
        index = 0;
    }
    else if(m_resolution == "1280*760 60P")
    {
        index = 1;
    }
    else if(m_resolution == "1920*1080 30P")
    {
        index = 2;
    }
    else
    {
        index = 3;
    }

    m_listWidget->setCurrentRow(index);
    m_listWidget->show();
}

void CVideoSetting::slotShowVideoCodeList(void)
{
    m_listWidget->setFocus();

    new QListWidgetItem(tr("H.264"), m_listWidget);
    new QListWidgetItem(tr("H.265"), m_listWidget);

    ui->navTipconfigLable->setText("视频编码");
    ui->navTipconfigLable->show();

    auto index = 0;
    if(m_resolution == "H.264")
    {
        index = 0;
    }
    else
    {
        index = 1;
    }

    m_listWidget->setCurrentRow(index);
    m_listWidget->show();
//    m_listWidget->item(0)->setTextColor(Qt::red);
}

void CVideoSetting::clearListWidgetItem(void)
{
    m_listWidget->hide();
    while(m_listWidget->count() > 0)
    {
        QListWidgetItem *item = m_listWidget->takeItem(0);
        delete item;
    }

    return;
}

void CVideoSetting::slotSetResolution(QString val)
{
    QTableWidgetItem *item = new QTableWidgetItem(val);
    item->setTextAlignment(Qt::AlignRight);
    ui->tableWidget->setItem(0, 1, item);
    m_resolution = val.toStdString();

    clearListWidgetItem();
    ui->tableWidget->setFocus();
    ui->navTipconfigLable->hide();

    return;
}

void CVideoSetting::slotSetVideoCode(QString val)
{
    QTableWidgetItem *item = new QTableWidgetItem(val);
    item->setTextAlignment(Qt::AlignRight);
    ui->tableWidget->setItem(1, 1, item);
    m_videoCode = val.toStdString();

    clearListWidgetItem();
    ui->tableWidget->setFocus();
    ui->navTipconfigLable->hide();

    return;
}

void CVideoSetting::keyPressEvent(QKeyEvent *ev)
{
    if(ui->tableWidget->hasFocus())
    {
        if(ev->key() == Qt::Key_Return)
        {
            auto currRow = ui->tableWidget->currentRow();
            if(currRow == 0)
            {
                emit signalShowResolutionList();
            }
            else
            {
                emit signalShowVideoCodeList();
            }

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
            auto currRow = m_listWidget->currentRow();
            QString val = m_listWidget->item(currRow)->text();
            if(ui->tableWidget->currentRow() == 0)
            {
                emit signalSetResolution(val);
            }
            else
            {
                emit signalSetVideoCode(val);
            }

            return;
        }

        if(ev->key() == Qt::Key_Escape)
        {
            clearListWidgetItem();
            m_listWidget->hide();
            QWidget::keyPressEvent(ev);
            return;
        }
    }

    return;
}
