#include "AppMain.h"
#include <QDebug>

AppMain::AppMain(QObject *parent) : QObject(parent)
{
    mAppWindow = std::shared_ptr<AppWindow>(new AppWindow());
    mWifiController = std::shared_ptr<WifiController>(new WifiController());
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
    if (nullptr == mView) {
        mView = new QQuickView();
    }

    if (mView == nullptr)
        return false;

    registerContextProperty();
    registerEnumType();

    mAppWindow->createWindow(mView);
    return true;
}

void AppMain::initAppMain()
{
    if (createWindow())
    {
        mWifiController->init();
    }
}

void AppMain::registerContextProperty()
{
    mView->rootContext()->setContextProperty("myAppMain", this);
    mView->rootContext()->setContextProperty("wifiController", mWifiController.get());
    mView->rootContext()->setContextProperty("wifiDeviceModel", mWifiController->getWifiDeviceModel());
}

void AppMain::registerEnumType()
{
//    qmlRegisterType<Enums>("Enums", 1, 0, "Enums");
}
