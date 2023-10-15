#ifndef WIFICONTROLLER
#define WIFICONTROLLER

#include <QObject>
#include <memory>
#include <WifiInterface.h>
#include <Model/WifiDeviceModel.h>

class WifiController : public QObject {
    Q_OBJECT

public:
    WifiController();
    ~WifiController();
    void init();

    WifiDeviceModel* getWifiDeviceModel()
    {
        return mWifiDeviceModel;
    }

private:
    void updatePairedDeviceList(std::vector<WifiDevice*>);
    void updateConnectedDevice(WifiDevice *);

    signal::Connect mUpdatePairedListSignal;
    signal::Connect mUpdateConnectedDeviceSignal;

private:
    WifiInterface* mWifiIF {nullptr};
    WifiDeviceModel* mWifiDeviceModel {nullptr};
    WifiDevice* mConnectedDevice {nullptr};
    QVector<AbstractInterface*> mInterfaces;
};

#endif // WIFICONTROLLER
