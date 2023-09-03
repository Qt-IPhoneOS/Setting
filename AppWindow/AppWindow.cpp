#include "AppWindow.h"

AppWindow::AppWindow()
{
}

AppWindow::~AppWindow()
{
    m_view = nullptr;
}

void AppWindow::createWindow(QQuickView *view)
{
    if (nullptr == view)
        return;

    const QUrl url("qrc:/Setting/Screen/main.qml");
    view->setWidth(700);
    view->setHeight(1100);
    view->setSource(url);
    view->show();
}
