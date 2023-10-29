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

    Q_ENUM(ScreenID)

};

#endif // ENUMS_H
