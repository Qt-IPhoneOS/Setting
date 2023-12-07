#include "SystemSettingController.h"
#include <QDebug>

SystemSettingController::SystemSettingController(QObject* parent)
    : QObject(parent)
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
        setIsAirplaneModeActive(false);
        break;
    case SystemSettingAdapter::AirplaneModeEnums::Active:
        setIsAirplaneModeActive(true);
        break;
    default:
        setIsAirplaneModeActive(false);
        break;
    }
}

void SystemSettingController::setNewValueAirplaneMode(const bool& newAirplaneMode) {
    mSysAdapter.setNewAirplaneMode(static_cast<SystemSettingAdapter::AirplaneModeEnums>(newAirplaneMode));
}

bool SystemSettingController::isAirplaneModeActive() const
{
    return m_isAirplaneModeActive;
}

void SystemSettingController::setIsAirplaneModeActive(bool newIsAirplaneModeActive)
{
    if (m_isAirplaneModeActive == newIsAirplaneModeActive)
        return;
    m_isAirplaneModeActive = newIsAirplaneModeActive;
    emit isAirplaneModeActiveChanged();
}
