#ifndef WIFICONTROLLER
#define WIFICONTROLLER

#include <QObject>
#include <memory>
#include <WifiAdapter.h>
#include <Model/WifiDeviceModel.h>

class WifiController : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool wifiOn READ wifiOn WRITE setWifiOn NOTIFY wifiOnChanged)

public:
    WifiController(const std::shared_ptr<WifiDeviceModel>&);
    ~WifiController();
    void init();

    Q_INVOKABLE void setEnableWifi(const bool& enable);
    Q_INVOKABLE void connectDevice(const QString& addr);

    bool wifiOn() const;
    void setWifiOn(bool newWifiOn);

signals:
    void wifiOnChanged();

private:
    void updatePairedDeviceList(std::vector<WifiDevice*>);
    void updateConnectedDevice(WifiDevice *);

    signal::Connect mUpdatePairedList;
    signal::Connect mUpdateConnectedDevice;
    signal::Connect mUpdateEnableWifi;

private:
    WifiAdapter* mWifiAdapter {nullptr};
    WifiDevice* mConnectedDevice {nullptr};
    std::shared_ptr<WifiDeviceModel> mWifiDeviceModel;
    QVector<AbstractInterface*> mInterfaces;
    bool m_wifiOn {false};
};

#endif // WIFICONTROLLER
