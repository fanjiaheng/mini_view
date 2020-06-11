#pragma once

#include <QApplication>

class CMainView;

namespace MiniView
{

class CMiniView
{
public:
    CMiniView();
    ~CMiniView();

    bool init(int argc, char *argv[]);
    int exec();

private:
    QApplication* m_app;
    CMainView* m_view;
};


}// namespace MiniView



