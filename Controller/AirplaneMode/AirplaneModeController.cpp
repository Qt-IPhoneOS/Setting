#include "AirplaneModeController.h"

AirplaneModeController::AirplaneModeController() {

}

AirplaneModeController::AirplaneModeController(std::shared_ptr<AirplaneModeModel>& airplaneModelObj) {
    mAirplaneModelObj = airplaneModelObj;
}

AirplaneModeController::~AirplaneModeController() {

}

AirplaneModeController& AirplaneModeController::getInstance() {
    static AirplaneModeController instance(&std::make_shared<AirplaneModeModel>());
    return instance;
}

void AirplaneModeController::setAirplaneModelIns(const std::shared_ptr<AirplaneModeModel>& newObject) {
    mAirplaneModelObj = newObject;
}