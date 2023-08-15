#include "AppMain.h"
#include "Common/Enums.h"
#include <QDebug>

AppMain::AppMain(QObject *parent) : QObject(parent)
{
    m_appWindow = std::shared_ptr<AppWindow>(new AppWindow());
    mController = std::shared_ptr<WifiController>(new WifiController());
}

AppMain::~AppMain()
{

}

AppMain *AppMain::instance()
{
    static AppMain* ins = new AppMain();
    return ins;
}

bool AppMain::createWindow()
{
    if (nullptr == m_view) {
        m_view = new QQuickView();
    }

    if (m_view == nullptr)
        return false;

    registerContextProperty();
    registerEnumType();

    m_appWindow->createWindow(m_view);
    return true;
}

void AppMain::initAppMain()
{
    if (createWindow())
    {
        mController->initWifiController();
    }
}

void AppMain::registerContextProperty()
{
    m_view->rootContext()->setContextProperty("myAppMain", this);
    m_view->rootContext()->setContextProperty("homeController", mController.get());
}

void AppMain::registerEnumType()
{
    qmlRegisterType<Enums>("Enums", 1, 0, "Enums");
}
