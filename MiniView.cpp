#include "MiniView.h"
#include "MainView.h"


namespace MiniView
{

CMiniView::CMiniView(): m_app(nullptr), m_view(nullptr)
{

}

CMiniView::~CMiniView()
{
    delete m_app;
}

bool CMiniView::init(int argc, char *argv[])
{
    m_app = new QApplication(argc, argv);

    return true;
}

int CMiniView::exec()
{
    m_view = new CMainView();
    m_view->show();

    return m_app->exec();
}


} // namespace MiniView
