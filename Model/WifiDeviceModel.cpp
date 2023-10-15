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
//    case Name:
//        result = QString::fromStdString(mWifiDeviceList.at(index.row())->getName());
//        break;
//    case SpeedMode:
//        result = (int)mWifiDeviceList.at(index.row())->getSpeedMode();
//        break;
//    case DeviceType:
//        result = (int)mWifiDeviceList.at(index.row())->getDeviceType();
//        break;
//    case Address:
//        result = QString::fromStdString(mWifiDeviceList.at(index.row())->getAddress());
//        break;
//    case PrivateAddress:
//        result = mWifiDeviceList.at(index.row())->getPrivateAddress();
//        break;
//    case IP:
//        result = (int)mWifiDeviceList.at(index.row())->getIP();
//        break;
//    case DNS:
//        result = (int)mWifiDeviceList.at(index.row())->getDNS();
//        break;
//    case Proxy:
//        result = (int)mWifiDeviceList.at(index.row())->getProxy();
//        break;
//    case Password:
//        result = QString::fromStdString(mWifiDeviceList.at(index.row())->getPassword());
//        break;
//    case LowDataMode:
//        result = (int)mWifiDeviceList.at(index.row())->getLowDataMode();
//        break;
//    case LimitIP:
//        result = (int)mWifiDeviceList.at(index.row())->getLimitIP();
//        break;
//    case IPAddress:
//        result = QString::fromStdString(mWifiDeviceList.at(index.row())->getIPAddress());
//        break;
//    case Subnet:
//        result = QString::fromStdString(mWifiDeviceList.at(index.row())->getSubnet());
//        break;
//    case Router:
//        result = QString::fromStdString(mWifiDeviceList.at(index.row())->getRouter());
//        break;
//    case State:
//        result = (int)mWifiDeviceList.at(index.row())->getState();
//        break;
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
