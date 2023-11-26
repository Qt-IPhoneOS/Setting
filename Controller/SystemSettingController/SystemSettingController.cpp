#include "SystemSettingController.h"
#include <QDebug>

SystemSettingController::SystemSettingController(QObject* parent)
    : QObject(parent)
    , mSystemSettingModel(QSharedPointer<SystemSettingModel>(new SystemSettingModel()))
//    , mSysAdapter(SystemSettingAdapter::getInstance())
{
//    mUpdateAirplaneMode = mSysAdapter.notifyUpdateAirplaneMode.connect([this](const SystemSettingAdapter::AirplaneModeEnums& _airplaneMode) {
//        QMetaObject::invokeMethod(this, "handleUpdateAirplaneMode", Q_ARG(SystemSettingAdapter::AirplaneModeEnums, _airplaneMode));
//    });
}

SystemSettingController::~SystemSettingController() {
    
}

void SystemSettingController::handleUpdateAirplaneMode(const SystemSettingAdapter::AirplaneModeEnums& _newAirplaneMode) {
    
}

void SystemSettingController::setNewAirplaneMode(const bool& newAirplaneMode) {
    qWarning() << "setNewAirplaneMode value: " << newAirplaneMode;
//    mSysAdapter.setNewAirplaneMode(static_cast<SystemSettingAdapter::AirplaneModeEnums>(newAirplaneMode));
}
