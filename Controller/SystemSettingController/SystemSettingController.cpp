#include "SystemSettingController.h"

SystemSettingController::SystemSettingController(QObject* parent)
    : QObject(parent)
    , mSystemSettingModel(QSharedPointer<SystemSettingModel>(new SystemSettingModel()))
    , mSysAdapter(SystemSettingAdapter::getInstance())
{
    mUpdateAirplaneMode = mSysAdapter.notifyUpdateAirplaneMode.connect(QMetaObject::invokeMethod(this, "handleUpdateAirplaneMode", Qt::QueuedConnection, Q_ARG(SystemSettingAdapter::AirplaneModeEnums, _newAirplaneMode)));
}

SystemSettingController::~SystemSettingController() {
    
}

void SystemSettingController::handleUpdateAirplaneMode(const SystemSettingAdapter::AirplaneModeEnums& _newAirplaneMode) {
    
}

bool SystemSettingController::setNewAirplaneMode(const bool& newAirplaneMode) {
    mSysAdapter.setNewAirplaneMode(static_cast<SystemSettingAdapter::AirplaneModeEnums>(newAirplaneMode));
}
