#include "WifiController.h"
#include <QDebug>

WifiController::WifiController() : mAdapter(WifiAdapter::instance())
{
    mInterfaces.push_back(mAdapter);

    mPairedDeviceModel = std::make_shared<WifiDeviceModel>();
    mDiscoveryModel = std::make_shared<WifiDeviceModel>();

    mUpdatePairedDevices = mAdapter->onPairedDeviceChanged.connect([this](std::vector<WifiDevice*> devices){
        QMetaObject::invokeMethod(this, "handleUpdatePairedDevices", Qt::QueuedConnection, Q_ARG(std::vector<WifiDevice*>, devices));
    });

    mUpdateConnectedDevice = mAdapter->onConnectedDeviceChanged.connect([this](WifiDevice* device) {
        QMetaObject::invokeMethod(this, "handleUpdateConnectedDevice", Qt::QueuedConnection, Q_ARG(WifiDevice*, device));
    });

    mUpdateEnableWifi = mAdapter->onWifiEnableChanged.connect([this](bool enable) {
        QMetaObject::invokeMethod(this, "handleUpdateEnableWifi", Qt::QueuedConnection, Q_ARG(bool, enable));
    });

    mUpdateConnectDeviceState = mAdapter->onDeviceStateChanged.connect([this](const std::string& addr, const WifiDevice::State& oldState, const WifiDevice::State& newState) {
        QMetaObject::invokeMethod(this, "handleUpdateDeviceState", Qt::QueuedConnection,
                                  Q_ARG(const std::string&, addr), Q_ARG(Enums::WifiState, static_cast<Enums::WifiState>(oldState)), Q_ARG(Enums::WifiState, static_cast<Enums::WifiState>(newState)));
    });

   mUpdateDiscoveryDevice = mAdapter->onDiscoveryDeviceUpdated.connect([this](const WifiAdapter::DiscoveryAction& action, const WifiDevice::DeviceInfo& device) {
       QMetaObject::invokeMethod(this, "handleUpdateDiscoveryDevice", Qt::QueuedConnection,
                                 Q_ARG(const WifiAdapter::DiscoveryAction&, action), Q_ARG(const WifiDevice::DeviceInfo&, device));
   });
}

WifiController::~WifiController()
{
    for (auto& interface : mInterfaces) {
        interface->disconnect();
    }

    mInterfaces.clear();

    delete mAdapter;
}

void WifiController::init()
{
    for (auto interface : mInterfaces) {
        interface->connect();
    }
}

void WifiController::handleUpdateConnectedDevice(WifiDevice* device)
{
    setConnectedName(QString::fromStdString(device->getDeviceInfo().mName));
    setConnectedStatus(Enums::DeviceConnected);
}

void WifiController::handleUpdateEnableWifi(bool enable)
{
    setWifiOn(enable);
}

void WifiController::handleUpdateDiscoveryDevice(const WifiAdapter::DiscoveryAction &action, const WifiDevice::DeviceInfo &devInfo)
{
    WifiDevice* device = new WifiDevice(devInfo);

    mDiscoveryModel->appendItem(device);
}

void WifiController::handleUpdateDeviceState(const std::string &name, Enums::WifiState oldState, Enums::WifiState newState)
{
    Q_UNUSED(oldState);

    switch (newState) {
    case Enums::WaitingAuthen:
    case Enums::AuthenSuccess:
        setConnectedName(QString::fromStdString(name));
        setConnectedStatus(Enums::DeviceConnecting);
        break;
    case Enums::Paired:
    case Enums::Unknown:
    case Enums::Unpaired:
    case Enums::Connected:
    case Enums::AuthenFail:
    case Enums::CheckingSSID:
    case Enums::CheckingSSIDFail:
    case Enums::CheckingSSIDSuccess:
        break;
    }

}

void WifiController::handleUpdatePairedDevices(std::vector<WifiDevice*> devices)
{
    QVector<WifiDevice*> qVector;
    qVector.reserve(devices.size());

    for (const auto& item : devices) {
        qVector.append(item);
    }
    mPairedDeviceModel->appendDevices(qVector);
}

void WifiController::setEnableWifi(const bool& enable)
{
    if (mAdapter == nullptr)
        return;

    mAdapter->setEnableWifi(enable);
}

void WifiController::connectDevice(const QString &addr)
{
    if (mAdapter == nullptr)
        return;

    mAdapter->connectDevice(addr.toStdString());
}

void WifiController::startDiscovery()
{
    if (mAdapter == nullptr)
        return;

    mAdapter->startDiscovery();
}

bool WifiController::wifiOn() const
{
    return mWifiOn;
}

void WifiController::setWifiOn(bool newWifiOn)
{
    if (mWifiOn == newWifiOn)
        return;
    mWifiOn = newWifiOn;
    emit wifiOnChanged();
}

QString WifiController::connectedName() const
{
    return mConnectedName;
}

void WifiController::setConnectedName(const QString &newConnectedName)
{
    if (mConnectedName == newConnectedName)
        return;
    mConnectedName = newConnectedName;
    emit connectedNameChanged();
}

Enums::ConnectedState WifiController::connectedStatus() const
{
    return mConnectedStatus;
}

void WifiController::setConnectedStatus(Enums::ConnectedState newConnectedStatus)
{
    if (mConnectedStatus == newConnectedStatus)
        return;
    mConnectedStatus = newConnectedStatus;
    emit connectedStatusChanged();
}
