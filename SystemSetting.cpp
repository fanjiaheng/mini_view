#include "SystemSetting.h"
#include "ui_SystemSetting.h"
#include "SystemSetting/DeviceMaintain.h"
#include "SystemSetting/DeviceManage.h"
#include "SystemSetting/EventManage.h"
#include "SystemSetting/PlatformSetting.h"
#include "SystemSetting/SystemInfo.h"
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

    // 系统信息
    m_sysInfoUi = new CSystemInfo(this);
    m_sysInfoUi->init();
    m_sysInfoUi->hide();

    // 设备管理
    m_deviceManageUi = new CDeviceManage(this);
    m_deviceManageUi->init();
    m_deviceManageUi->hide();

    // 设备维护
    m_deviceMaintainUi = new CDeviceMaintain(this);
    m_deviceMaintainUi->init();
    m_deviceMaintainUi->hide();

    // 平台设置
    m_platformSettingUi = new CPlatformSetting(this);
    m_platformSettingUi->init();
    m_platformSettingUi->hide();

    // 事件管理
    m_eventManageUi = new CEventManage(this);
    m_eventManageUi->init();
    m_eventManageUi->hide();

    connect(this, SIGNAL(signalDeviceManage()), SLOT(slotDeviceManage()));
    connect(this, SIGNAL(signalEventManage()), SLOT(slotEventManage()));
    connect(this, SIGNAL(signalPlatformSetting()), SLOT(slotPlatformSetting()));
    connect(this, SIGNAL(signalDeviceMaintain()), SLOT(slotDeviceMaintain()));
    connect(this, SIGNAL(signalSystemInfo()), SLOT(slotSystemInfo()));
}

CSystemSetting::~CSystemSetting()
{
    delete  m_sysInfoUi;
    delete  m_deviceManageUi;
    delete  m_deviceMaintainUi;
    delete  m_platformSettingUi;
    delete  m_eventManageUi;
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
            auto currRow = ui->tableWidget->currentRow();
            if(currRow == 0)
            {
                emit signalDeviceManage();
            }
            else if(currRow == 1)
            {
                emit signalEventManage();
            }
            else if(currRow == 2)
            {
                emit signalPlatformSetting();
            }
            else if(currRow == 3)
            {
                emit signalDeviceMaintain();
            }
            else
            {
                emit signalSystemInfo();
            }

            return;
        }

        if(ev->key() == Qt::Key_Escape)
        {
            QWidget::keyPressEvent(ev); // 抛出事件
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
            switch(m_currStatus)
            {
            case SystemSettingNav::DEVICEMANAGESTATUS:
                {
                    m_deviceManageUi->hide();
                }
                break;
            case SystemSettingNav::EVENTMANAGESTATUS:
                {
                    m_eventManageUi->hide();
                }
                break;
            case SystemSettingNav::PLATFORMSETTINGMANAGESTATUS:
                {
                    m_platformSettingUi->hide();
                }
                break;
            case SystemSettingNav::DEVICEMAINTAINSTATUS:
                {
                    m_deviceMaintainUi->hide();
                }
                break;
            case SystemSettingNav::SYSTEMINFOSTATUS:
                {
                    m_sysInfoUi->hide();
                }
                break;
            default:
                break;
            }

            m_currStatus = SystemSettingNav::SYSTEMSTATUS;
            ui->tableWidget ->setFocus();
        }
    }

    return;
}

void CSystemSetting::slotDeviceManage(void)
{
    m_currStatus = SystemSettingNav::DEVICEMANAGESTATUS;
    m_deviceManageUi->show();
    m_deviceManageUi->pre();
}

void CSystemSetting::slotEventManage(void)
{
    m_currStatus = SystemSettingNav::EVENTMANAGESTATUS;
    m_eventManageUi->show();
    m_eventManageUi->pre();
}

void CSystemSetting::slotPlatformSetting(void)
{
    m_currStatus = SystemSettingNav::PLATFORMSETTINGMANAGESTATUS;
    m_platformSettingUi->show();
    m_platformSettingUi->pre();
}

void CSystemSetting::slotDeviceMaintain(void)
{
    m_currStatus = SystemSettingNav::DEVICEMAINTAINSTATUS;
    m_deviceMaintainUi->show();
    m_deviceMaintainUi->pre();
}

void CSystemSetting::slotSystemInfo(void)
{
    m_currStatus = SystemSettingNav::SYSTEMINFOSTATUS;
    m_sysInfoUi->show();
    m_sysInfoUi->pre();
}
