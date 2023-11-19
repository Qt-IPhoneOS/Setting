#include "SettingController.h"
#include <QDebug>

SettingController::SettingController() 
    : mAirplaneController(AirplaneModeController::getInstance()) 
{
    qWarning() << "Constructor setting controller";
}

SettingController::~SettingController() {

}

void SettingController::initialized() {
    mAirplaneController.init();
}

void SettingController::registerContext(const QQuickView* mViewer) {
    if (mViewer) {
        qWarning() << "Register context for setting";
        mViewer->rootContext()->setContextProperty("AirplaneController", &mAirplaneController);
    }
}