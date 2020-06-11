#pragma once

#include <QWidget>

namespace Ui {
class MainMenu;
}

class CVideoSetting;
class CCameraSetting;
class CNetSetting;
class CSystemSetting;

enum class MenuNav: int
{
    MAINMENU = 1,   // 主菜单导航索引
    VIDEOINDEX,     // 视频导航索引
    CAMERAINDEX,    // 拍照导航索引
    NETINDEX,       // 网络导航索引
    SYSTEMINDEX     // 系统导航索引
};

class CMainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit CMainMenu(QWidget *parent = nullptr);
    ~CMainMenu();

    void init();
    void pre();

private slots:
    void ClickVideoBtn();
    void ClickCameraBtn();
    void ClickNetBtn();
    void ClickSettingBtn();

protected:
    virtual void keyPressEvent(QKeyEvent *ev);

private:
    Ui::MainMenu *ui;
    CVideoSetting *m_videoSet;
    CCameraSetting *m_cameraSet;
    CNetSetting *m_netSet;
    CSystemSetting *m_sysSet;
    MenuNav m_currNavIndex;
};
