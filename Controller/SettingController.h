#ifndef SETTINGCONTROLLER_H
#define SETTINGCONTROLLER_H

#include <QObject>
#include <QQuickView>
#include <QQmlContext>
#include <memory>
#include "../AppWindow/AppWindow.h"
#include "Wifi/WifiController.h"
#include "ScreenNavigator/ScreenNavigator.h"

class SettingController : public QObject
{
    Q_OBJECT

public:
    explicit SettingController(QObject *parent = nullptr);
    ~SettingController();

    bool createWindow();
    void initSettingController();
    void registerContextProperty();
    void registerEnumType();

private:
    QQuickView* mView {nullptr};
    AppWindow* mAppWindow {nullptr};
    WifiController* mWifiController {nullptr};
    ScreenNavigator* mScreens;
    std::shared_ptr<WifiDeviceModel> mWifiDeviceModel;
};

#endif // SETTINGCONTROLLER_H
