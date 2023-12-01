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
    mScreenQueue->registerRootScreen(Enums::SET_Main, "qrc:/Resources/Screens/SET_Main.qml");
    mScreenQueue->registerChildScreen(Enums::SET_Main, Enums::SET_WifiMenu, "qrc:/Resources/Screens/Wifi/SET_WifiMenu.qml");

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
    mScreenQueue->getViewer()->rootContext()->setContextProperty("WifiPairedModel", mWifiController->getPairedDeviceModel().get());
    mScreenQueue->getViewer()->rootContext()->setContextProperty("WifiDiscoveryModel", mWifiController->getDiscoveryDeviceModel().get());
    mScreenQueue->getViewer()->rootContext()->setContextProperty("SystemSettingController", mSystemSettingController);
}

void SettingEngine::registerEnumType()
{
    qmlRegisterType<Enums>("Enums", 1, 0, "Enums");
}

void SettingEngine::showScreen(const uchar &screen)
{
    mScreenQueue->showNextScreen(screen);
}

void SettingEngine::backScreen()
{
    mScreenQueue->showPreviousScreen();
}
