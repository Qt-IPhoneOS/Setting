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

void SystemSettingController::handleUpdateDataSystemSetting(midlayer::SystemSettingAdapter::ID_CALLBACK idEvent, const int& dataEvent)
{
    if (idEvent == midlayer::SystemSettingAdapter::ID_CALLBACK::None) {
        return;
    }
    switch (idEvent) {

    case midlayer::SystemSettingAdapter::ID_CALLBACK::Airplane_Mode:
        setIsAirplaneModeActive(dataEvent);
        break;
    case midlayer::SystemSettingAdapter::ID_CALLBACK::Cellular_Network:
        setisCellularStatus(static_cast<bool>(dataEvent));
        break;
    case midlayer::SystemSettingAdapter::ID_CALLBACK::Personal_Hotspot:
        break;
    case midlayer::SystemSettingAdapter::ID_CALLBACK::Allow_Others_To_Join:
        setIsEnableJoinNetwork(static_cast<bool>(dataEvent));
        break;
    case midlayer::SystemSettingAdapter::ID_CALLBACK::Maximize_Compaxibility:
        setIsMaximizeCompatibility(static_cast<bool>(dataEvent));
    default:
        break;
    }

}

void SystemSettingController::setNewValueAirplaneMode(const bool& newAirplaneMode) {
    mSysAdapter.setNewAirplaneMode(static_cast<midlayer::SystemSettingAdapter::AirplaneModeEnums>(newAirplaneMode));
}

void SystemSettingController::setEnableOthersJoinNetwork(const bool &status)
{
    mSysAdapter.setIsAllowOthersToJoin(status);
}

void SystemSettingController::setIsCellularStatus(const bool & status)
{

}

void SystemSettingController::setMaximizeCompatibility(const bool &status)
{
    mSysAdapter.setIsMaximizeCompatibility(status);
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

bool SystemSettingController::isCellularStatus() const
{
    return m_isCellularStatus;
}

void SystemSettingController::setisCellularStatus(bool newIsCellularStatus)
{
    if (m_isCellularStatus == newIsCellularStatus)
        return;
    m_isCellularStatus = newIsCellularStatus;
    emit onisCellularStatusChanged();
}

bool SystemSettingController::isEnableJoinNetwork() const
{
    return m_isEnableJoinNetwork;
}

void SystemSettingController::setIsEnableJoinNetwork(bool newIsEnableJoinNetwork)
{
    if (m_isEnableJoinNetwork == newIsEnableJoinNetwork)
        return;
    m_isEnableJoinNetwork = newIsEnableJoinNetwork;
    emit onIsEnableJoinNetworkChanged();
}

bool SystemSettingController::isMaximizeCompatibility() const
{
    return m_isMaximizeCompatibility;
}

void SystemSettingController::setIsMaximizeCompatibility(bool newIsMaximizeCompatibility)
{
    if (m_isMaximizeCompatibility == newIsMaximizeCompatibility)
        return;
    m_isMaximizeCompatibility = newIsMaximizeCompatibility;
    emit onIsMaximizeCompatibilityChanged();
}
