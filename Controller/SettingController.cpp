#include "SettingController.h"

SettingController::SettingController() 
    : mAirplaneController(AirplaneModeController::getInstance()) 
{

}

SettingController::~SettingController() {

}

void SettingController::initialized() {

}

void SettingController::registerContext(const QQuickView* mViewer) {
    if (mViewer) {
        mViewer->rootContext()->setContextProperty("AirplaneController", &mAirplaneController);
    }
}