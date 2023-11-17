#ifndef SETTINGCONTROLLER_H
#define SETTINGCONTROLLER_H

#include <QObject>
#include "AirplaneMode/AirplaneModeController.h"
#include <QQuickView>
#include <QQmlContext>

class SettingController : public QObject {
public:
    SettingController();
    ~SettingController();

public:
    void initialized();
    void registerContext(const QQuickView* mViewer);

private:
    AirplaneModeController& mAirplaneController;
};

#endif //SETTINGCONTROLLER_H