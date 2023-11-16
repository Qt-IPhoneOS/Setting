#ifndef WIFICONTROLLER
#define WIFICONTROLLER

#include <QObject>
#include <memory>
#include <WifiAdapter.h>
#include <Model/WifiDeviceModel.h>
#include <Enums.h>
#include <Log.h>

class WifiController : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool wifiOn READ wifiOn WRITE setWifiOn NOTIFY wifiOnChanged)
    Q_PROPERTY(QString connectedName READ connectedName WRITE setConnectedName NOTIFY connectedNameChanged)
    Q_PROPERTY(Enums::ConnectedState connectedStatus READ connectedStatus WRITE setConnectedStatus NOTIFY connectedStatusChanged)

public:
    WifiController(const std::shared_ptr<WifiDeviceModel>&);
    ~WifiController();
    void init();

    Q_INVOKABLE void setEnableWifi(const bool& enable);
    Q_INVOKABLE void connectDevice(const QString& addr);
    Q_INVOKABLE void startDiscovery();

    bool wifiOn() const;
    void setWifiOn(bool newWifiOn);

    QString connectedName() const;
    void setConnectedName(const QString &newConnectedName);

    Enums::ConnectedState connectedStatus() const;
    void setConnectedStatus(Enums::ConnectedState newConnectedStatus);

signals:
    void wifiOnChanged();
    void connectedNameChanged();

    void connectedStatusChanged();

public slots:
    void handleUpdatePairedDevices(std::vector<WifiDevice*>);
    void handleUpdateDeviceState(const std::string&, Enums::WifiState, Enums::WifiState);
    void handleUpdateConnectedDevice(WifiDevice*);
    void handleUpdateEnableWifi(bool);

private:
    signal::Connect mUpdatePairedDevices;
    signal::Connect mUpdateConnectedDevice;
    signal::Connect mUpdateEnableWifi;
    signal::Connect mUpdateConnectDeviceState;
    signal::Connect mUpdateDiscoveryDevice;

private:
    WifiAdapter* mAdapter {nullptr};
    std::shared_ptr<WifiDeviceModel> mDeviceModel;
    QVector<AbstractInterface*> mInterfaces;
    bool mWifiOn {false};
    QString mConnectedName {""};
    Enums::ConnectedState mConnectedStatus {Enums::DeviceConnected};
};

#endif // WIFICONTROLLER
