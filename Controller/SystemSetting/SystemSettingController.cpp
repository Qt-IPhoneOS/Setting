#include "SystemSettingController.h"
#include <QDebug>

#define CHECK_VALID_QVARIANT(A) (true == A.isValid() && false == A.isNull())

SystemSettingController::SystemSettingController(QObject* parent)
    : QObject(parent)
    , mSysAdapter(midlayer::SystemSettingAdapter::instance())
{
    mUpdateDataSystemSetting = mSysAdapter.notifyUpdateDataSystemSeting.connect([this](const midlayer::SystemSettingAdapter::ID_CALLBACK idEvent, const int& dataEvent){
        QMetaObject::invokeMethod(this, "handleUpdateDataSystemSetting", Q_ARG(midlayer::SystemSettingAdapter::ID_CALLBACK, idEvent), Q_ARG(int, dataEvent));
    });
}

SystemSettingController::~SystemSettingController() {
    
}

void SystemSettingController::handleUpdateDataSystemSetting(midlayer::SystemSettingAdapter::ID_CALLBACK eventID, const int& dataEvent)
{
    if (eventID == midlayer::SystemSettingAdapter::ID_CALLBACK::None)
        return;

    switch (eventID) {
    case midlayer::SystemSettingAdapter::ID_CALLBACK::Airplane_Mode:
        setIsAirplaneModeActive(static_cast<bool>(dataEvent));
        break;
    default:
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


