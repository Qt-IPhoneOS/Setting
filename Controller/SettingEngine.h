#ifndef SETTINGENGINE_H
#define SETTINGENGINE_H

#include <QObject>
#include <QQuickView>
#include <QQmlContext>
#include <memory>
#include "Wifi/WifiController.h"
#include "ScreenNavigator/ScreenNavigator.h"

class SettingEngine : public QObject
{
    Q_OBJECT

public:
    explicit SettingEngine(QObject *parent = nullptr);
    ~SettingEngine();

    bool createWindow();
    void init();
    void registerContextProperty();
    void registerEnumType();

private:
    QQuickView* mView {nullptr};
    WifiController* mWifiController {nullptr};
    ScreenNavigator* mScreens;
    std::shared_ptr<WifiDeviceModel> mWifiDeviceModel;
};

#endif // SETTINGENGINE_H
