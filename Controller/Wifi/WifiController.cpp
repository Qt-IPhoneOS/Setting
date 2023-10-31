#include "WifiController.h"
#include <QDebug>

WifiController::WifiController(const std::shared_ptr<WifiDeviceModel>& model) : mWifiAdapter(WifiAdapter::instance()), mWifiDeviceModel(model)
{
    mInterfaces.push_back(mWifiAdapter);

    mUpdatePairedList = mWifiAdapter->onPairedDeviceChanged.connect(std::bind(&WifiController::updatePairedDeviceList, this, std::placeholders::_1));
    mUpdateConnectedDevice = mWifiAdapter->onConnectedDeviceChanged.connect(std::bind(&WifiController::updateConnectedDevice, this, std::placeholders::_1));
    mUpdateEnableWifi = mWifiAdapter->onWifiEnableChanged.connect(std::bind(&WifiController::updateEnableWifi, this, std::placeholders::_1));
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

void WifiController::updateEnableWifi(bool enable)
{
    setWifiOn(enable);
}

void WifiController::setEnableWifi(const bool& enable)
{
    if (mWifiAdapter == nullptr)
        return;

    mWifiAdapter->setEnableWifi(enable);
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
