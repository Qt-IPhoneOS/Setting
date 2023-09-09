#include "WifiController.h"
#include <QDebug>

WifiController::WifiController() : mWifiIF(WifiInterface::instance()), mWifiDeviceModel(new WifiDeviceModel())
{
    mInterfaces.push_back(mWifiIF);

    mUpdatePairedListSignal = mWifiIF->getAdapter().onPairedDeviceChanged.connect(std::bind(&WifiController::updatePairedDeviceList, this, std::placeholders::_1));
    mUpdateConnectedDeviceSignal = mWifiIF->getAdapter().onConnectedDeviceChanged.connect(std::bind(&WifiController::updateConnectedDevice, this, std::placeholders::_1));
}

WifiController::~WifiController()
{
    for (auto& interface : mInterfaces) {
        interface->disconnect();
    }

    mInterfaces.clear();

    delete mWifiIF;
    delete mWifiDeviceModel;
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
}
