#include "SIMController.h"
#include <QDebug>

SIMController::SIMController(QObject *parent)
    : QObject(parent)
    , mSIMAdapter(midlayer::SIMAdapter::instance())
{
    mUpdateDataSIMService = mSIMAdapter.notifyUpdateDataSIMService.connect([this](midlayer::SIMAdapter::ID_CALLBACK eventID, const int& dataEvent){
        QMetaObject::invokeMethod(this, "handleUpdateDataSIMService", Q_ARG(midlayer::SIMAdapter::ID_CALLBACK, eventID), Q_ARG(int, dataEvent));
    });
}

SIMController::~SIMController()
{

}

void SIMController::handleUpdateDataSIMService(midlayer::SIMAdapter::ID_CALLBACK eventID, const int& dataEvent)
{
    if (eventID == midlayer::SIMAdapter::ID_CALLBACK::None)
        return;

    switch(eventID) {
    case midlayer::SIMAdapter::ID_CALLBACK::Cellular_Data:
        setisCellularStatus(static_cast<bool>(dataEvent));
        break;
    case midlayer::SIMAdapter::ID_CALLBACK::Personal_Hotspot:
        break;
    case midlayer::SIMAdapter::ID_CALLBACK::Allow_Others_To_Join:
        setIsEnableJoinNetwork(static_cast<bool>(dataEvent));
        break;
    case midlayer::SIMAdapter::ID_CALLBACK::Maximize_Compaxibility:
        setIsMaximizeCompatibility(static_cast<bool>(dataEvent));
    default:
        break;
    }
}

void SIMController::setEnableOthersJoinNetwork(const bool& status)
{
    mSIMAdapter.setIsAllowOthersToJoin(status);
}

void SIMController::setIsCellularStatus(const bool& status)
{
    mSIMAdapter.setIsCellularDataStatus(status);
}

void SIMController::setMaximizeCompatibility(const bool& status)
{
    mSIMAdapter.setIsMaximizeCompatibility(status);
}


bool SIMController::isCellularStatus() const
{
    return m_isCellularStatus;
}

void SIMController::setisCellularStatus(bool newIsCellularStatus)
{
    if (m_isCellularStatus == newIsCellularStatus)
        return;
    m_isCellularStatus = newIsCellularStatus;
    emit onisCellularStatusChanged();
}

bool SIMController::isEnableJoinNetwork() const
{
    return m_isEnableJoinNetwork;
}

void SIMController::setIsEnableJoinNetwork(bool newIsEnableJoinNetwork)
{
    if (m_isEnableJoinNetwork == newIsEnableJoinNetwork)
        return;
    m_isEnableJoinNetwork = newIsEnableJoinNetwork;
    emit onIsEnableJoinNetworkChanged();
}

bool SIMController::isMaximizeCompatibility() const
{
    return m_isMaximizeCompatibility;
}

void SIMController::setIsMaximizeCompatibility(bool newIsMaximizeCompatibility)
{
    if (m_isMaximizeCompatibility == newIsMaximizeCompatibility)
        return;
    m_isMaximizeCompatibility = newIsMaximizeCompatibility;
    emit onIsMaximizeCompatibilityChanged();
}

