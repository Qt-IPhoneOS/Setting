#ifndef ENUMS_H
#define ENUMS_H

#include <QObject>

class Enums : public QObject {
    Q_OBJECT
public:
    Enums()
    {
    }

    enum ScreenID {
        SET_Main,
        // Wifi
        SET_WifiMenu,
        SET_WifiDevice
    };

    enum WifiState {
        Unknown,
        Unpaired,
        CheckingSSID,
        CheckingSSIDFail,
        CheckingSSIDSuccess,
        Paired,
        WaitingAuthen,
        AuthenFail,
        AuthenSuccess
    };

    enum ConnectedState {
        DeviceConnecting,
        DeviceConnected
    };

    Q_ENUM(ScreenID)
    Q_ENUM(WifiState)
    Q_ENUM(ConnectedState)

};

#endif // ENUMS_H
