#include "AirplaneModeController.h"

AirplaneModeController::AirplaneModeController(const std::shared_ptr<AirplaneModeModel>& airplaneModelObj) 
    : mSettingAdapter(SettingAdapter::getInstance())
{
    mAirplaneModelObj = airplaneModelObj;
    mUpdateAirplaneMode = mSettingAdapter.onAirplaneModeChanged.connect(std::bind(&AirplaneModeController::onNotifyAirplaneModeChanged, this, std::placeholders::_1));
}

AirplaneModeController::~AirplaneModeController() {
    mSettingAdapter.doDisconnect();
}

AirplaneModeController& AirplaneModeController::getInstance() {
    static AirplaneModeController instance(std::make_shared<AirplaneModeModel>(new AirplaneModeModel()));
    return instance;
}

void AirplaneModeController::init() {
    printf("\ninit do connect 1111");
    bool resultConnect = mSettingAdapter.doConnect();
    if (resultConnect) {
        printf("\nConnect service succes .....");    
    }
}

void AirplaneModeController::onNotifyAirplaneModeChanged(const middlewarelayer::AirplaneMode& airplaneMode) {
    printf("\nHerreee CB in modelllllllllll");
    switch (airplaneMode)
    {
    case middlewarelayer::AirplaneMode::Inactivve:
        mAirplaneModelObj.get()->setIsAirplaneModeActive(false);
        break;
    case middlewarelayer::AirplaneMode::Active:
        mAirplaneModelObj.get()->setIsAirplaneModeActive(true);
        break;
    default:
        break;
    }
}

void AirplaneModeController::setNewAirplaneMode(const bool& newStatus) {
    qWarning() << "\nSet new airplane mode" << newStatus;
    printf("\nHREEEEEEEEEEEEEEEEEEE 1111111111111");
    if (newStatus) {
        printf("\nHREEEEEEEEEEEEEEEEEEE 1111111111111 22222222222222");
        mSettingAdapter.setAirplaneMode(middlewarelayer::AirplaneMode::Inactivve);
    } else {
        mSettingAdapter.setAirplaneMode(middlewarelayer::AirplaneMode::Active);
    }
}
