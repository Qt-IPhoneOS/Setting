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
        MainScreen,
        // Wifi
        WifiMainScreen
    };

    enum State {
        UnknownState,
        UnpairedState,
        CheckingSSIDState,
        CheckingSSIDFailState,
        CheckingSSIDSuccessState,
        PairedState,
        WaitingAuthenState,
        AuthenFailState,
        AuthenSuccessState,
        ConnectedState
    };

    Q_ENUM(ScreenID)

};

#endif // ENUMS_H
