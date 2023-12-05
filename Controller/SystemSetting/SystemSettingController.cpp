#include "SystemSettingController.h"
#include <QDebug>

SystemSettingController::SystemSettingController(QObject* parent)
    : QObject(parent)
    , mSystemSettingModel(QSharedPointer<SystemSettingModel>(new SystemSettingModel()))
    , mSysAdapter(SystemSettingAdapter::instance())
{
    mUpdateAirplaneMode = mSysAdapter.notifyUpdateAirplaneMode.connect([this](const SystemSettingAdapter::AirplaneModeEnums& _airplaneMode) {
        QMetaObject::invokeMethod(this, "handleUpdateAirplaneMode", Q_ARG(SystemSettingAdapter::AirplaneModeEnums, _airplaneMode));
    });
}

SystemSettingController::~SystemSettingController() {
    
}

void SystemSettingController::handleUpdateAirplaneMode(const SystemSettingAdapter::AirplaneModeEnums& _newAirplaneMode) {
    switch(_newAirplaneMode) {
    case SystemSettingAdapter::AirplaneModeEnums::Inactive:
        mSystemSettingModel->setIsActiveAirplaneMode(false);
        break;
    case SystemSettingAdapter::AirplaneModeEnums::Active:
        mSystemSettingModel->setIsActiveAirplaneMode(true);
        break;
    default:
        break;
    }
}

void SystemSettingController::setNewAirplaneMode(const bool& newAirplaneMode) {
    mSysAdapter.setNewAirplaneMode(static_cast<SystemSettingAdapter::AirplaneModeEnums>(newAirplaneMode));
}
