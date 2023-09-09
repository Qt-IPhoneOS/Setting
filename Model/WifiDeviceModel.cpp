#include "WifiDeviceModel.h"
#include <QDebug>

WifiDeviceModel::WifiDeviceModel(QObject* parent) : QAbstractListModel(parent)
{
}

WifiDeviceModel::~WifiDeviceModel()
{
    mWifiDeviceList.clear();
}

int WifiDeviceModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mWifiDeviceList.size();
}

QVariant WifiDeviceModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant{};

    if (index.row() >= mWifiDeviceList.size() || index.row() < 0)
        return QVariant{};

    QVariant result;
    switch(role) {
    case Name:
        result = QString::fromStdString(mWifiDeviceList.at(index.row())->mName);
        break;
    case SpeedMode:
        result = (int)mWifiDeviceList.at(index.row())->mSpeedMode;
        break;
    case DeviceType:
        result = (int)mWifiDeviceList.at(index.row())->mDeviceType;
        break;
    case Address:
        result = QString::fromStdString(mWifiDeviceList.at(index.row())->mAddress);
        break;
    case PrivateAddress:
        result = mWifiDeviceList.at(index.row())->mPrivateAddr;
        break;
    case IP:
        result = (int)mWifiDeviceList.at(index.row())->mIP;
        break;
    case DNS:
        result = (int)mWifiDeviceList.at(index.row())->mDNS;
        break;
    case Proxy:
        result = (int)mWifiDeviceList.at(index.row())->mProxy;
        break;
    case Password:
        result = QString::fromStdString(mWifiDeviceList.at(index.row())->mPassword);
        break;
    case LowDataMode:
        result = (int)mWifiDeviceList.at(index.row())->mLowDataMode;
        break;
    case LimitIP:
        result = (int)mWifiDeviceList.at(index.row())->mLimitIP;
        break;
    case IPAddress:
        result = QString::fromStdString(mWifiDeviceList.at(index.row())->mIPAddress);
        break;
    case Subnet:
        result = QString::fromStdString(mWifiDeviceList.at(index.row())->mSubnet);
        break;
    case Router:
        result = QString::fromStdString(mWifiDeviceList.at(index.row())->mRouter);
        break;
    case State:
        result = (int)mWifiDeviceList.at(index.row())->mState;
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
    roles[DeviceType] = "type";
    roles[Address] = "addr";
    roles[PrivateAddress] = "privateAddr";
    roles[IP] = "ip";
    roles[DNS] = "dns";
    roles[Proxy] = "proxy";
    roles[Password] = "password";
    roles[LowDataMode] = "lowData";
    roles[LimitIP] = "limitIP";
    roles[IPAddress] = "ipAddress";
    roles[Subnet] = "subnet";
    roles[Router] = "router";
    roles[State] = "state";
    return roles;
}

void WifiDeviceModel::appendItem(QVector<WifiDevice*>& deviceList)
{
    if (deviceList.size() > 0)
        mWifiDeviceList.clear();

    beginResetModel();
    mWifiDeviceList = deviceList;
    setCount(deviceList.size());
    endResetModel();
}

int WifiDeviceModel::count() const
{
    return mWifiDeviceList.size();
}

void WifiDeviceModel::setCount(int newCount)
{
    if (mCount == newCount)
        return;
    mCount = newCount;
    emit countChanged();
}
