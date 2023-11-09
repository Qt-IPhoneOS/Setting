#ifndef WIFICONTROLLER
#define WIFICONTROLLER

#include <QObject>
#include <memory>
#include <WifiAdapter.h>
#include <Model/WifiDeviceModel.h>

class WifiController : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool wifiOn READ wifiOn WRITE setWifiOn NOTIFY wifiOnChanged)
    Q_PROPERTY(QString connectedName READ connectedName WRITE setConnectedName NOTIFY connectedNameChanged)

public:
    WifiController(const std::shared_ptr<WifiDeviceModel>&);
    ~WifiController();
    void init();

    Q_INVOKABLE void setEnableWifi(const bool& enable);
    Q_INVOKABLE void connectDevice(const QString& addr);

    bool wifiOn() const;
    void setWifiOn(bool newWifiOn);

    QString connectedName() const;
    void setConnectedName(const QString &newConnectedName);

signals:
    void wifiOnChanged();

    void connectedNameChanged();

private:
    void updatePairedDeviceList(std::vector<WifiDevice*>);

    signal::Connect mUpdatePairedList;
    signal::Connect mUpdateConnectedDevice;
    signal::Connect mUpdateEnableWifi;
    signal::Connect mUpdateConnectDeviceState;

private:
    WifiAdapter* mWifiAdapter {nullptr};
    WifiDevice* mConnectedDevice {nullptr};
    std::shared_ptr<WifiDeviceModel> mWifiDeviceModel;
    QVector<AbstractInterface*> mInterfaces;
    bool m_wifiOn {false};
    QString m_connectedName;
};

#endif // WIFICONTROLLER
