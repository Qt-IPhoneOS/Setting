#include "AirplaneModeModel.h"

AirplaneModeModel::AirplaneModeModel(QObject* parent) 
    : QObject(parent)
{

}

AirplaneModeModel::~AirplaneModeModel() {
    
}

bool AirplaneModeModel::isAirplaneModeActive() const {
    return m_isAirplaneModeActive;
}

void AirplaneModeModel::setIsAirplaneModeActive(const bool& newStatus) {
    if (m_isAirplaneModeActive == newStatus)
        return;
    m_isAirplaneModeActive = newStatus;
    emit onIsAirplaneModeChanged();
}