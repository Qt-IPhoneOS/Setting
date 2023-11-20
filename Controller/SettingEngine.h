#ifndef SETTINGENGINE_H
#define SETTINGENGINE_H

#include <QObject>
#include <QQuickView>
#include <QQmlContext>
#include <memory>
#include "Wifi/WifiController.h"
#include "ScreenNavigator/ScreenNavigator.h"
#include "SettingController.h"

class SettingEngine : public QObject
{
    Q_OBJECT

public:
    explicit SettingEngine(QObject *parent = nullptr);
    ~SettingEngine();

    bool createWindow();
    void initialized();
    void registerContextProperty();
    void registerEnumType();

private:
    QQuickView* mView {nullptr};
    WifiController* mWifiController {nullptr};
    ScreenNavigator* mScreens;
    SettingController* mSettingController {nullptr};

};

#endif // SETTINGENGINE_H
