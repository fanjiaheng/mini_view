#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QKeyEvent>
#include <QDebug>


CMainWindow::CMainWindow(QWidget *parent): QWidget(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_parent = parent;
}

CMainWindow::~CMainWindow()
{

}

void CMainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key() == Qt::Key_Escape)
    {
        QWidget::keyPressEvent(ev);
    }
}

void CMainWindow::init()
{

}

void CMainWindow::pre()
{

}
