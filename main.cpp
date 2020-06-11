#include "MiniView.h"


int main(int argc, char *argv[])
{
    MiniView::CMiniView* app = new MiniView::CMiniView();

    app->init(argc, argv);
    app->exec();

    return 0;
}
