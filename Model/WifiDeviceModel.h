#ifndef WIFIDEVICEMODEL_H
#define WIFIDEVICEMODEL_H

#include <QAbstractListModel>
#include <QVariant>
#include <QVector>
#include <WifiAdapter.h>

class WifiDeviceModel : public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
public:
    WifiDeviceModel(QObject* parent = nullptr);
    ~WifiDeviceModel();
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    void appendDevices(QVector<WifiDevice*>& deviceList);
    void appendItem(WifiDevice* device);


    int count() const;
    void setCount(int newCount);

signals:
    void countChanged();

private:
    enum Role {
        Name,
        Address,
        PrivateAddress,
        Password,
        AutoConnect,
        SpeedMode
    };

    QVector<WifiDevice*> mWifiDevices;
    int mCount;
};

#endif // WIFIDEVICEMODEL_H
