#include "SystemSettingController.h"
#include <QDebug>

SystemSettingController::SystemSettingController(QObject* parent)
    : QObject(parent)
    , mSysAdapter(midlayer::SystemSettingAdapter::instance())
{
    mUpdateAirplaneMode = mSysAdapter.notifyUpdateAirplaneMode.connect([this](const midlayer::SystemSettingAdapter::AirplaneModeEnums& _airplaneMode) {
        QMetaObject::invokeMethod(this, "handleUpdateAirplaneMode", Q_ARG(midlayer::SystemSettingAdapter::AirplaneModeEnums, _airplaneMode));
    });
}

SystemSettingController::~SystemSettingController() {
    
}

void SystemSettingController::handleUpdateAirplaneMode(const midlayer::SystemSettingAdapter::AirplaneModeEnums& _newAirplaneMode) {
    switch(_newAirplaneMode) {
    case midlayer::SystemSettingAdapter::AirplaneModeEnums::Inactive:
        setIsAirplaneModeActive(false);
        break;
    case midlayer::SystemSettingAdapter::AirplaneModeEnums::Active:
        setIsAirplaneModeActive(true);
        break;
    default:
        setIsAirplaneModeActive(false);
        break;
    }
}

void SystemSettingController::setNewValueAirplaneMode(const bool& newAirplaneMode) {
    mSysAdapter.setNewAirplaneMode(static_cast<midlayer::SystemSettingAdapter::AirplaneModeEnums>(newAirplaneMode));
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
