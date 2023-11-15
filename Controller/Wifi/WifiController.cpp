#include "WifiController.h"
#include <QDebug>

WifiController::WifiController(const std::shared_ptr<WifiDeviceModel>& model) : mWifiAdapter(WifiAdapter::instance()), mWifiDeviceModel(model)
{
    mInterfaces.push_back(mWifiAdapter);

    mUpdatePairedDevices = mWifiAdapter->onPairedDeviceChanged.connect([this](std::vector<WifiDevice*> devices){
        QMetaObject::invokeMethod(this, "handleUpdatePairedDevices", Qt::QueuedConnection, Q_ARG(std::vector<WifiDevice*>, devices));
    }) ;

    mUpdateConnectedDevice = mWifiAdapter->onConnectedDeviceChanged.connect([this](WifiDevice* device) {
        QMetaObject::invokeMethod(this, "handleUpdateConnectedDevice", Qt::QueuedConnection, Q_ARG(WifiDevice*, device));
    });

    mUpdateEnableWifi = mWifiAdapter->onWifiEnableChanged.connect([this](bool enable) {
        QMetaObject::invokeMethod(this, "handleUpdateEnableWifi", Qt::QueuedConnection, Q_ARG(bool, enable));
    });

    mUpdateConnectDeviceState = mWifiAdapter->onDeviceStateChanged.connect([this](const std::string& addr, const WifiDevice::State& oldState, const WifiDevice::State& newState) {
        QMetaObject::invokeMethod(this, "handleUpdateDeviceState", Qt::QueuedConnection,
                                  Q_ARG(const std::string&, addr), Q_ARG(Enums::WifiState, static_cast<Enums::WifiState>(oldState)), Q_ARG(Enums::WifiState, static_cast<Enums::WifiState>(newState)));
    });
}

WifiController::~WifiController()
{
    for (auto& interface : mInterfaces) {
        interface->disconnect();
    }

    mInterfaces.clear();

    delete mWifiAdapter;
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

void WifiController::handleUpdateDeviceState(const std::string &name, Enums::WifiState oldState, Enums::WifiState newState)
{
    switch (newState) {
    case Enums::WaitingAuthen:
    case Enums::AuthenSuccess:
        setConnectedName(QString::fromStdString(name));
        setConnectedStatus(Enums::DeviceConnecting);
        break;
    case Enums::Unknown:
    case Enums::AuthenFail:
    case Enums::CheckingSSID:
    case Enums::CheckingSSIDFail:
    case Enums::CheckingSSIDSuccess:
    case Enums::Paired:
    case Enums::Connected:
    case Enums::Unpaired:
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
    mWifiDeviceModel->appendDevices(qVector);
}

void WifiController::setEnableWifi(const bool& enable)
{
    if (mWifiAdapter == nullptr)
        return;

    mWifiAdapter->setEnableWifi(enable);
}

void WifiController::connectDevice(const QString &addr)
{
    qWarning() << addr;

    if (mWifiAdapter == nullptr)
        return;

    mWifiAdapter->connectDevice(addr.toStdString());
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
