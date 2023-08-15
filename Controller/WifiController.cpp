#include "WifiController.h"

WifiController::WifiController()
{
    m_wifiIf = WifiInterface::instance();
    m_interfaces.push_back(m_wifiIf);
}

WifiController::~WifiController()
{
    for (auto& interface : m_interfaces) {
        interface->disconnect();
    }

    m_interfaces.clear();
}

void WifiController::initWifiController()
{
    for (auto interface : m_interfaces) {
        interface->connect();
    }
}
