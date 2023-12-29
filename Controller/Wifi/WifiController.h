#ifndef WIFICONTROLLER
#define WIFICONTROLLER

#include <QObject>
#include <memory>
#include <WifiAdapter.h>
#include <Enums.h>
#include <Log.h>
#include <Model/WifiDeviceModel.h>

class WifiController : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool wifiOn READ wifiOn WRITE setWifiOn NOTIFY wifiOnChanged)
    Q_PROPERTY(QString connectedName READ connectedName WRITE setConnectedName NOTIFY connectedNameChanged)
    Q_PROPERTY(Enums::ConnectedState connectedStatus READ connectedStatus WRITE setConnectedStatus NOTIFY connectedStatusChanged)
    Q_PROPERTY(QObject* singleDeviceObject READ singleDeviceObject WRITE setSingleDeviceObject NOTIFY singleDeviceObjectChanged)
public:
    WifiController(QObject* parent = nullptr);
    ~WifiController();
    void init();

    Q_INVOKABLE void setEnableWifi(const bool& enable);
    Q_INVOKABLE void connectDevice(const QString& addr);
    Q_INVOKABLE void startDiscovery();
    Q_INVOKABLE void sendParamsDevice(QObject* params);

    bool wifiOn() const;
    void setWifiOn(bool newWifiOn);

    QString connectedName() const;
    void setConnectedName(const QString &newConnectedName);

    Enums::ConnectedState connectedStatus() const;
    void setConnectedStatus(Enums::ConnectedState newConnectedStatus);

    inline std::shared_ptr<WifiDeviceModel> getPairedDeviceModel()
    {
        return mPairedDeviceModel;
    }

    inline std::shared_ptr<WifiDeviceModel> getDiscoveryDeviceModel()
    {
        return mDiscoveryModel;
    }

    QObject *singleDeviceObject() const;
    void setSingleDeviceObject(QObject *newSingleDeviceObject);

signals:
    void wifiOnChanged();
    void connectedNameChanged();
    void connectedStatusChanged();
    void transformParamsToScreen(QObject* params);
    void singleDeviceObjectChanged();

public slots:
    void handleUpdatePairedDeviceList(std::vector<midlayer::WifiDevice*>);
    void handleUpdateDeviceState(const std::string&, Enums::WifiState, Enums::WifiState);
    void handleUpdateConnectedDevice(midlayer::WifiDevice*);
    void handleUpdateEnableWifi(bool);
    void handleAddDiscoveryDevice(midlayer::WifiDevice*);
    void handleRemoveDiscoveryDevice(const std::string&);

private:
    uicommon::Connect mUpdatePairedDevices;
    uicommon::Connect mUpdateConnectedDevice;
    uicommon::Connect mUpdateEnableWifi;
    uicommon::Connect mUpdateConnectDeviceState;
    uicommon::Connect mAddDiscoveryDevice;
    uicommon::Connect mRemoveDiscoveryDevice;

private:
    midlayer::WifiAdapter* mAdapter {nullptr};
    std::shared_ptr<WifiDeviceModel> mPairedDeviceModel;
    std::shared_ptr<WifiDeviceModel> mDiscoveryModel;
    QVector<AbstractInterface*> mInterfaces;
    bool mWifiOn {false};
    QString mConnectedName {""};
    Enums::ConnectedState mConnectedStatus {Enums::DeviceConnected};
    QObject *m_singleDeviceObject = nullptr;
};

#endif // WIFICONTROLLER
