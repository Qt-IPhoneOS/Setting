#include "SettingEngine.h"
#include <QDebug>

SettingEngine::SettingEngine(QObject *parent) : QObject(parent)
{
    mWifiController = new WifiController();
    mScreens = ScreenNavigator::instance();
    mSettingController = new SettingController();
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
//        mSettingController->initialized();
        mWifiController->init();
    }
}

void SettingEngine::registerContextProperty()
{
    mView->rootContext()->setContextProperty("SettingEngine", this);
    mView->rootContext()->setContextProperty("WifiController", mWifiController);
    mView->rootContext()->setContextProperty("ScreenNavigator", mScreens);
    mView->rootContext()->setContextProperty("WifiPairedModel", mWifiController->getPairedDeviceModel().get());
    mView->rootContext()->setContextProperty("WifiDiscoveryModel", mWifiController->getDiscoveryDeviceModel().get());
    mSettingController->registerContext(mView);


}

void SettingEngine::registerEnumType()
{
    qmlRegisterType<Enums>("Enums", 1, 0, "Enums");
}
