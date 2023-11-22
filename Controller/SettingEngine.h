#ifndef SETTINGENGINE_H
#define SETTINGENGINE_H

#include <QObject>
#include <QQuickView>
#include <QQmlContext>
#include <memory>
#include "Wifi/WifiController.h"
#include "ScreenNavigator/ScreenNavigator.h"
#include "SystemSettingController/SystemSettingController.h"
class SettingEngine : public QObject
{
    Q_OBJECT
public:
    explicit SettingEngine(QObject *parent = nullptr);
    ~SettingEngine();

public:
    void init();
    bool createWindow();
    void registerContextProperty();
    void registerEnumType();

private:
    QQuickView*                     mView                       {nullptr};
    WifiController*                 mWifiController             {nullptr};
    ScreenNavigator*                mScreens                    {nullptr};
    SystemSettingController*        mSystemSettingController    {nullptr};

};

#endif // SETTINGENGINE_H
