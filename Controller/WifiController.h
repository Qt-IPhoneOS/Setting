#ifndef WIFICONTROLLER
#define WIFICONTROLLER

#include <QObject>
#include <memory>
#include "Interface/Wifi/WifiInterface.h"

class WifiController : public QObject {
    Q_OBJECT

public:
    WifiController();
    ~WifiController();
    void initWifiController();

private:

private:
    WifiInterface* m_wifiIf {nullptr};
    QVector<AbstractInterface*> m_interfaces;
};

#endif // WIFICONTROLLER
