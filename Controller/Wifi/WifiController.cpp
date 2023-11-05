#include "WifiController.h"
#include <QDebug>

WifiController::WifiController(const std::shared_ptr<WifiDeviceModel>& model) : mWifiAdapter(WifiAdapter::instance()), mWifiDeviceModel(model)
{
    mInterfaces.push_back(mWifiAdapter);

    mUpdatePairedList = mWifiAdapter->onPairedDeviceChanged.connect(std::bind(&WifiController::updatePairedDeviceList, this, std::placeholders::_1));
    mUpdateConnectedDevice = mWifiAdapter->onConnectedDeviceChanged.connect(std::bind(&WifiController::updateConnectedDevice, this, std::placeholders::_1));

    mUpdateEnableWifi = mWifiAdapter->onWifiEnableChanged.connect([this](bool enable) {
        setWifiOn(enable);
    });
}

WifiController::~WifiController()
{
    for (auto& interface : mInterfaces) {
        interface->disconnect();
    }

    mInterfaces.clear();

    delete mWifiAdapter;
    delete mConnectedDevice;
}

void WifiController::init()
{
    for (auto interface : mInterfaces) {
        interface->connect();
    }
}

void WifiController::updatePairedDeviceList(std::vector<WifiDevice*> devices)
{
    QVector<WifiDevice*> qVector;
    qVector.reserve(devices.size());

    for (const auto& item : devices) {
        qVector.append(item);
    }
    mWifiDeviceModel->appendItem(qVector);
}

void WifiController::updateConnectedDevice(WifiDevice *device)
{
//    mConnectedDevice = device;
    Q_UNUSED(device);
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
    return m_wifiOn;
}

void WifiController::setWifiOn(bool newWifiOn)
{
    if (m_wifiOn == newWifiOn)
        return;
    m_wifiOn = newWifiOn;
    emit wifiOnChanged();
}
