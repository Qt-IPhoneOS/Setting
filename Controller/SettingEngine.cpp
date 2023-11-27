#include "SettingEngine.h"
#include <QDebug>

SettingEngine::SettingEngine(QObject *parent) : QObject(parent)
{
    mWifiController = new WifiController();
    mScreenQueue = ScreenQueue::instance();
    mSystemSettingController = new SystemSettingController();
}

SettingEngine::~SettingEngine()
{
    delete mWifiController;
    delete mSystemSettingController;
}

bool SettingEngine::createWindow()
{
    registerContextProperty();
    registerEnumType();

    mScreenQueue->createView();
    mScreenQueue->registerRootScreen(Enums::MainScreen, "qrc:/Resources/Screens/MainSetting.qml");
    mScreenQueue->registerChildScreen(Enums::MainScreen, Enums::WifiMainScreen, "qrc:/Resources/Screens/Wifi/WifiMainSetting.qml");

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
    mScreenQueue->getViewer()->rootContext()->setContextProperty("SystemSettingController", mSystemSettingController);
    mScreenQueue->getViewer()->rootContext()->setContextProperty("SystemSettingModel", mSystemSettingController->systemSettingModelObject().get());
}

void SettingEngine::registerEnumType()
{
    qmlRegisterType<Enums>("Enums", 1, 0, "Enums");
}
