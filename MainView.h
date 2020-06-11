#pragma once

#include <QWidget>

namespace Ui {
class MainView;
}

class CMainWindow;
class CMainMenu;

class CMainView : public QWidget
{
    Q_OBJECT

public:
    explicit CMainView(QWidget *parent = nullptr);
    ~CMainView();

protected:
    virtual void keyPressEvent(QKeyEvent *ev);

private:
    Ui::MainView *ui;
    CMainWindow *m_mainWindow;
    CMainMenu *m_mainMenu;
};

