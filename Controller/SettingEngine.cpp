#include "SettingEngine.h"
#include <QDebug>

SettingEngine::SettingEngine(QObject *parent) : QObject(parent)
{
    mWifiController = new WifiController();
    mScreenQueue = ScreenQueue::instance();
    //mSettingController = new SettingController();
}

SettingEngine::~SettingEngine()
{
    delete mWifiController;
}

bool SettingEngine::createWindow()
{
    registerContextProperty();
    registerEnumType();

    mScreenQueue->createView();
    mScreenQueue->registerRootScreen(Enums::MainScreen, "qrc:/Screen/MainSetting.qml");
    mScreenQueue->registerChildScreen(Enums::MainScreen, Enums::WifiMainScreen, "qrc:/Screen/Wifi/WifiMainSetting.qml");

    return true;
}

void SettingEngine::initialized()
{

    if (createWindow())
    {
        mWifiController->init();
    }
}

void SettingEngine::registerContextProperty()
{
    mScreenQueue->getViewer()->rootContext()->setContextProperty("SettingEngine", this);
    mScreenQueue->getViewer()->rootContext()->setContextProperty("WifiController", mWifiController);
    mScreenQueue->getViewer()->rootContext()->setContextProperty("ScreenQueue", mScreenQueue);
    mScreenQueue->getViewer()->rootContext()->setContextProperty("WifiPairedModel", mWifiController->getPairedDeviceModel().get());
    mScreenQueue->getViewer()->rootContext()->setContextProperty("WifiDiscoveryModel", mWifiController->getDiscoveryDeviceModel().get());
    //mSettingController->registerContext(mView);


}

void SettingEngine::registerEnumType()
{
    qmlRegisterType<Enums>("Enums", 1, 0, "Enums");
}
