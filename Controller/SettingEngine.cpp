#include "SettingEngine.h"
#include <QDebug>

SettingEngine::SettingEngine(QObject *parent) : QObject(parent)
{
    mWifiDeviceModel = std::make_shared<WifiDeviceModel>(new WifiDeviceModel());
    mWifiController = new WifiController(mWifiDeviceModel);
    mScreens = ScreenNavigator::instance();
}

SettingEngine::~SettingEngine()
{
    delete mWifiController;
}

bool SettingEngine::createWindow()
{
    if (nullptr == mView) {
        mView = new QQuickView();
    }

    if (mView == nullptr)
        return false;

    registerContextProperty();
    registerEnumType();

    mView->setWidth(700);
    mView->setHeight(1100);
    mView->setSource(QUrl("qrc:/Setting/Screen/main.qml"));
    mView->show();

    return true;
}

void SettingEngine::init()
{

    if (createWindow())
    {
        mWifiController->init();
    }
}

void SettingEngine::registerContextProperty()
{
    mView->rootContext()->setContextProperty("SettingEngine", this);
    mView->rootContext()->setContextProperty("wifiController", mWifiController);
    mView->rootContext()->setContextProperty("screenNavigator", mScreens);
    mView->rootContext()->setContextProperty("wifiDeviceModel", mWifiDeviceModel.get());

}

void SettingEngine::registerEnumType()
{
    qmlRegisterType<Enums>("Enums", 1, 0, "Enums");
}
