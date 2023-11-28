#ifndef SETTINGENGINE_H
#define SETTINGENGINE_H

#include <QObject>
#include <memory>
#include <ScreenManager/ScreenQueue.h>
#include "Wifi/WifiController.h"
#include "SystemSetting/SystemSettingController.h"


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

    Q_INVOKABLE void showScreen(const uchar&);
    Q_INVOKABLE void backScreen();

private:
    WifiController*                 mWifiController             {nullptr};
    SystemSettingController*        mSystemSettingController    {nullptr};
    ScreenQueue*                    mScreenQueue                {nullptr};
};

#endif // SETTINGENGINE_H
