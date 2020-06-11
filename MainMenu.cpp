#include "MainMenu.h"
#include "ui_MainMenu.h"
#include "VideoSetting.h"
#include "CameraSetting.h"
#include "NetSetting.h"
#include "SystemSetting.h"
#include <QDebug>
#include <QKeyEvent>


CMainMenu::CMainMenu(QWidget *parent): QWidget(parent), ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    // 功能导航
    m_videoSet = new CVideoSetting(this);
    m_videoSet->hide();
    m_videoSet->init();

    m_cameraSet = new CCameraSetting(this);
    m_cameraSet->hide();
    m_cameraSet->init();

    m_netSet = new CNetSetting(this);
    m_netSet->hide();
    m_netSet->init();

    m_sysSet = new CSystemSetting(this);
    m_sysSet->hide();
    m_sysSet->init();

    connect(ui->videoBtn, SIGNAL(clicked()), this, SLOT(ClickVideoBtn()));
    connect(ui->cameraBtn, SIGNAL(clicked()), this, SLOT(ClickCameraBtn()));
    connect(ui->netBtn, SIGNAL(clicked()), this, SLOT(ClickNetBtn()));
    connect(ui->settingBtn, SIGNAL(clicked()), this, SLOT(ClickSettingBtn()));

    m_currNavIndex = MenuNav::MAINMENU;
}

CMainMenu::~CMainMenu()
{
    delete ui;
}

void CMainMenu::init()
{

}

void CMainMenu::pre()
{
    ui->videoBtn->setFocus();
}

void CMainMenu::ClickVideoBtn()
{
    ui->navWidget->hide();
    m_videoSet->show();
    m_videoSet->pre();
    m_currNavIndex = MenuNav::VIDEOINDEX;
}

void CMainMenu::ClickCameraBtn()
{
    ui->navWidget->hide();
    m_cameraSet->show();
    m_cameraSet->pre();
    m_currNavIndex = MenuNav::CAMERAINDEX;
}

void CMainMenu::ClickNetBtn()
{
    ui->navWidget->hide();
    m_netSet->show();
    m_netSet->pre();
    m_currNavIndex = MenuNav::NETINDEX;
}

void CMainMenu::ClickSettingBtn()
{
    ui->navWidget->hide();
    m_sysSet->show();
    m_sysSet->pre();
    m_currNavIndex = MenuNav::SYSTEMINDEX;
}

void CMainMenu::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key() == Qt::Key_Return)
    {
        if(ui->videoBtn->hasFocus())
        {
            emit ui->videoBtn->QPushButton::clicked();
        }
        else if(ui->cameraBtn->hasFocus())
        {
            emit ui->cameraBtn->QPushButton::clicked();
        }
        else if(ui->netBtn->hasFocus())
        {
            emit ui->netBtn->QPushButton::clicked();
        }
        else
        {
            emit ui->settingBtn->QPushButton::clicked();
        }

        return;
    }

    if(ev->key() == Qt::Key_Escape)
    {
        switch(m_currNavIndex)
        {
        case MenuNav::MAINMENU:
            {
                QWidget::keyPressEvent(ev);
            }
            break;
        case MenuNav::VIDEOINDEX:
            {
                m_videoSet->hide();
                ui->videoBtn->setFocus();
            }
            break;
        case MenuNav::CAMERAINDEX:
            {
                m_cameraSet->hide();
                ui->cameraBtn->setFocus();
            }
            break;
        case MenuNav::NETINDEX:
            {
                m_netSet->hide();
                ui->netBtn->setFocus();
            }
            break;
        case MenuNav::SYSTEMINDEX:
            {
                m_sysSet->hide();
                ui->settingBtn->setFocus();
            }
            break;
        }

        if(m_currNavIndex != MenuNav::MAINMENU)
        {
            ui->navWidget->show();
        }

        m_currNavIndex = MenuNav::MAINMENU;
    }

    return;
}
