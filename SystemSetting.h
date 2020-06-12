#pragma once

#include <QWidget>
#include <QListWidget>
#include <string>
#include <vector>

enum class SystemSettingNav: int
{
    SYSTEMSTATUS = 1,            // 系统设置状态
    DEVICEMANAGESTATUS,          // 设备管理状态
    EVENTMANAGESTATUS,           // 事件管理状态
    PLATFORMSETTINGMANAGESTATUS, // 平台管理状态
    DEVICEMAINTAINSTATUS,        // 设备维护状态
    SYSTEMINFOSTATUS             // 系统信息状态
};

namespace Ui {
class SystemSetting;
}

class CSystemInfo;
class CDeviceManage;
class CDeviceMaintain;
class CPlatformSetting;
class CEventManage;

class CSystemSetting : public QWidget
{
    Q_OBJECT

public:
    explicit CSystemSetting(QWidget *parent = nullptr);
    ~CSystemSetting();

    void init();
    void pre();

signals:
    void signalDeviceManage(void);
    void signalEventManage(void);
    void signalPlatformSetting(void);
    void signalDeviceMaintain(void);
    void signalSystemInfo(void);

private slots:
    void slotDeviceManage(void);
    void slotEventManage(void);
    void slotPlatformSetting(void);
    void slotDeviceMaintain(void);
    void slotSystemInfo(void);

protected:
    virtual void keyPressEvent(QKeyEvent *ev);

private:
    Ui::SystemSetting *ui;
    CSystemInfo *m_sysInfoUi;
    CDeviceManage *m_deviceManageUi;
    CDeviceMaintain *m_deviceMaintainUi;
    CPlatformSetting *m_platformSettingUi;
    CEventManage *m_eventManageUi;
    SystemSettingNav m_currStatus;
};
