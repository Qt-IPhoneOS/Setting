#include "WifiInterface.h"
#include <Wifi/WifiServiceAdapter.h>
#include <Wifi/WifiServiceProxy.h>
#include <QDebug>

/**
 * WifiInterfacePrivate
*/
class WifiInterfacePrivate {
public:
    WifiInterfacePrivate(WifiInterface& interface);
    ~WifiInterfacePrivate();

    WifiInterface& mWifiIF;
    WifiServiceProxy* mWifiServiceProxy {nullptr};
    WifiServiceAdapter* mWifiServiceAdapter {nullptr};

    void connectEvent();
    void disconnectEvent();

    void responseLocalIPAddress(const std::string& address);
    void responseWifiSpeedMode(const Wifi_SpeedMode& speedMode);
};

WifiInterfacePrivate::WifiInterfacePrivate(WifiInterface &interface) : mWifiIF(interface), mWifiServiceAdapter(WifiServiceAdapter::instance()),
                                                                        mWifiServiceProxy(WifiServiceProxy::instance())
{
    mWifiServiceAdapter->connectEvent.reqCallbackFunc(std::bind(&WifiInterfacePrivate::connectEvent, this));
    mWifiServiceAdapter->disconnectEvent.reqCallbackFunc(std::bind(&WifiInterfacePrivate::disconnectEvent, this));
}

WifiInterfacePrivate::~WifiInterfacePrivate()
{
}

void WifiInterfacePrivate::connectEvent()
{
}

void WifiInterfacePrivate::disconnectEvent()
{
    mWifiServiceAdapter->connectEvent.unReqCallbackFunc();
    mWifiServiceAdapter->disconnectEvent.unReqCallbackFunc();
}

/**
 * WifiInterface
*/
WifiInterface::WifiInterface()
{
    mWifiPriv = new WifiInterfacePrivate(*this);

    if (mWifiPriv->mWifiServiceProxy == nullptr)
        throw std::runtime_error("Create WifiService backend is failed");
}

WifiInterface::~WifiInterface()
{
    delete mWifiPriv;
}

WifiInterface *WifiInterface::instance()
{
    static WifiInterface* ins = new WifiInterface();
    return ins;
}

bool WifiInterface::doConnect()
{
    mWifiPriv->mWifiServiceProxy->connectService();
    return true;
}

bool WifiInterface::doDisconnect()
{
    mWifiPriv->mWifiServiceProxy->disconnectService();
    return true;
}
