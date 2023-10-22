#include "SettingController.h"
#include <QDebug>

SettingController::SettingController(QObject *parent) : QObject(parent)
{
    mAppWindow = new AppWindow();
    mWifiDeviceModel = std::make_shared<WifiDeviceModel>(new WifiDeviceModel());
    mWifiController = new WifiController(mWifiDeviceModel);
}

SettingController::~SettingController()
{
    delete mAppWindow;
    delete mWifiController;
}

bool SettingController::createWindow()
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

void SettingController::initSettingController()
{
    if (createWindow())
    {
        mWifiController->init();
    }
}

void SettingController::registerContextProperty()
{
    mView->rootContext()->setContextProperty("settingController", this);
    mView->rootContext()->setContextProperty("wifiController", mWifiController);
    mView->rootContext()->setContextProperty("wifiDeviceModel", mWifiDeviceModel.get());
}

void SettingController::registerEnumType()
{
//    qmlRegisterType<Enums>("Enums", 1, 0, "Enums");
}
