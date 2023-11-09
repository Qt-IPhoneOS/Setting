#include "WifiDeviceModel.h"
#include <QDebug>

WifiDeviceModel::WifiDeviceModel(QObject* parent) : QAbstractListModel(parent)
{
}

WifiDeviceModel::~WifiDeviceModel()
{
    mWifiDevices.clear();
}

int WifiDeviceModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mWifiDevices.size();
}

QVariant WifiDeviceModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant{};

    if (index.row() >= mWifiDevices.size() || index.row() < 0)
        return QVariant{};

    QVariant result;
    switch(role) {
    case Name:
        result = QString::fromStdString(mWifiDevices.at(index.row())->getDeviceInfo().mName);
        break;
    case Address:
        result = QString::fromStdString(mWifiDevices.at(index.row())->getDeviceInfo().mAddress);
        break;
    case PrivateAddress:
        result = mWifiDevices.at(index.row())->getDeviceInfo().mPrivateAddress;
        break;
    case Password:
        result = QString::fromStdString(mWifiDevices.at(index.row())->getPassword());
        break;
    case AutoConnect:
        result = (int)mWifiDevices.at(index.row())->getAutoConnect();
        break;
    case SpeedMode:
        result = (int)mWifiDevices.at(index.row())->getSpeedMode();
        break;
    default:
        break;
    }

    return result;
}

QHash<int, QByteArray> WifiDeviceModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Name] = "name";
    roles[SpeedMode] = "speedMode";
    roles[Address] = "addr";
    roles[PrivateAddress] = "privateAddr";
    roles[Password] = "password";
    roles[AutoConnect] = "autoConnect";
    return roles;
}

void WifiDeviceModel::appendDevices(QVector<WifiDevice*>& deviceList)
{
    if (deviceList.size() > 0)
        mWifiDevices.clear();

    beginResetModel();
    mWifiDevices = deviceList;
    setCount(deviceList.size());
    endResetModel();
}

int WifiDeviceModel::count() const
{
    return mWifiDevices.size();
}

void WifiDeviceModel::setCount(int newCount)
{
    if (mCount == newCount)
        return;
    mCount = newCount;
    emit countChanged();
}
