#include "MainView.h"
#include "ui_MainView.h"
#include "MainWindow.h"
#include "MainMenu.h"
#include <QKeyEvent>
#include <QDebug>


CMainView::CMainView(QWidget *parent): QWidget(parent), ui(new Ui::MainView)
{
    ui->setupUi(this);

    m_mainMenu = new CMainMenu(this);
    m_mainMenu->hide();

    //default show
    m_mainWindow = new CMainWindow(this);
    m_mainWindow->show();
    m_mainWindow->setFocus();
}

CMainView::~CMainView()
{
    delete m_mainMenu;
    delete m_mainWindow;
    delete ui;
}

void CMainView::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key() == Qt::Key_Escape)
    {
        if(m_mainWindow->hasFocus())
        {
            m_mainWindow->hide();
            m_mainMenu->show();
            m_mainMenu->pre();
        }
        else
        {
            m_mainMenu->hide();
            m_mainWindow->show();
            m_mainWindow->setFocus();
        }
    }

    return;
}

