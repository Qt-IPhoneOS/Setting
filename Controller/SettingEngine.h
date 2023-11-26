#ifndef SETTINGENGINE_H
#define SETTINGENGINE_H

#include <QObject>
#include <memory>
#include "Wifi/WifiController.h"
#include "ScreenNavigator/ScreenQueue.h"
#include "SystemSettingController/SystemSettingController.h"


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
    WifiController*                 mWifiController             {nullptr};
    SystemSettingController*        mSystemSettingController    {nullptr};
    ScreenQueue*                    mScreenQueue                {nullptr};
};

#endif // SETTINGENGINE_H
