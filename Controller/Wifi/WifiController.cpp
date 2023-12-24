#include "WifiController.h"
#include <QDebug>

WifiController::WifiController(QObject* parent)
    : mAdapter(midlayer::WifiAdapter::instance())
    , QObject(parent)
{
    mInterfaces.push_back(mAdapter);

    mPairedDeviceModel = std::make_shared<WifiDeviceModel>();
    mDiscoveryModel = std::make_shared<WifiDeviceModel>();

    mUpdatePairedDevices = mAdapter->onPairedDeviceListChanged.connect([this](std::vector<midlayer::WifiDevice*> devices){
        QMetaObject::invokeMethod(this, "handleUpdatePairedDeviceList", Qt::QueuedConnection, Q_ARG(std::vector<midlayer::WifiDevice*>, devices));
    });

    mUpdateConnectedDevice = mAdapter->onConnectedDeviceChanged.connect([this](midlayer::WifiDevice* device) {
        QMetaObject::invokeMethod(this, "handleUpdateConnectedDevice", Qt::QueuedConnection, Q_ARG(midlayer::WifiDevice*, device));
    });

    mUpdateEnableWifi = mAdapter->onWifiEnableChanged.connect([this](bool enable) {
        QMetaObject::invokeMethod(this, "handleUpdateEnableWifi", Qt::QueuedConnection, Q_ARG(bool, enable));
    });

    mUpdateConnectDeviceState = mAdapter->onDeviceStateChanged.connect([this](const std::string& addr, const midlayer::WifiAdapter::State& oldState, const midlayer::WifiAdapter::State& newState) {
        QMetaObject::invokeMethod(this, "handleUpdateDeviceState", Qt::QueuedConnection,
                                  Q_ARG(const std::string&, addr), Q_ARG(Enums::WifiState, static_cast<Enums::WifiState>(oldState)), Q_ARG(Enums::WifiState, static_cast<Enums::WifiState>(newState)));
    });

    mAddDiscoveryDevice = mAdapter->onAddDiscoveryDevice.connect([this](midlayer::WifiDevice* device) {
       QMetaObject::invokeMethod(this, "handleAddDiscoveryDevice", Qt::QueuedConnection, Q_ARG(midlayer::WifiDevice*, device));
    });

    mRemoveDiscoveryDevice = mAdapter->onRemoveDiscoveryDevice.connect([this](const std::string& addr) {
        QMetaObject::invokeMethod(this, "handleRemoveDiscoveryDevice", Qt::QueuedConnection, Q_ARG(const std::string&, addr));
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

void WifiController::handleUpdateConnectedDevice(midlayer::WifiDevice* device)
{
    setConnectedName(QString::fromStdString(device->getDeviceInfo().mName));
    setConnectedStatus(Enums::DeviceConnected);
}

void WifiController::handleUpdateEnableWifi(bool enable)
{
    setWifiOn(enable);
}

void WifiController::handleAddDiscoveryDevice(midlayer::WifiDevice* device)
{
    mDiscoveryModel->appendDevice(device);
}

void WifiController::handleRemoveDiscoveryDevice(const std::string &addr)
{
    mDiscoveryModel->removeDevice(addr);
}

void WifiController::handleUpdateDeviceState(const std::string &name, Enums::WifiState oldState, Enums::WifiState newState)
{
    Q_UNUSED(oldState);
    qWarning() << "newState: " << newState;

    switch (newState) {
    case Enums::WaitingAuthen:
    case Enums::AuthenSuccess:
    case Enums::CheckingSSID:
    case Enums::CheckingSSIDSuccess:
        setConnectedName(QString::fromStdString(name));
        setConnectedStatus(Enums::DeviceConnecting);
        break;
    case Enums::Paired:
    case Enums::Unknown:
    case Enums::Unpaired:
    case Enums::AuthenFail:
    case Enums::CheckingSSIDFail:
        break;
    }

}

void WifiController::handleUpdatePairedDeviceList(std::vector<midlayer::WifiDevice*> devices)
{
    QVector<midlayer::WifiDevice*> qVector;
    qVector.reserve(devices.size());

    for (const auto& item : devices) {
        qVector.append(item);
    }
    mPairedDeviceModel->setDevicelist(qVector);
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

void WifiController::sendParamsDevice(QObject* params)
{
    qWarning() << "WifiController::sendParamsDevice -- nameDevice: " << params->property("deviceName").toString() << " -- type: " << params->property("typeDeviceConnect").toInt();
    if (params == nullptr) return;
    setSingleDeviceObject(params);
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

QObject *WifiController::singleDeviceObject() const
{
    return m_singleDeviceObject;
}

void WifiController::setSingleDeviceObject(QObject *newSingleDeviceObject)
{
    if (m_singleDeviceObject == newSingleDeviceObject)
        return;
    m_singleDeviceObject = newSingleDeviceObject;
    emit singleDeviceObjectChanged();
}
