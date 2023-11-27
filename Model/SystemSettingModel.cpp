#include "SystemSettingModel.h"

SystemSettingModel::SystemSettingModel(QObject* parent) 
    : QObject(parent)
{

}

SystemSettingModel::~SystemSettingModel() {
    
}

bool SystemSettingModel::isActiveAirplaneMode() const {
    return mIsActiveAirplaneMode;
}

void SystemSettingModel::setIsActiveAirplaneMode(const bool& newStatus) {
    if (mIsActiveAirplaneMode == newStatus)
        return;
    mIsActiveAirplaneMode = newStatus;
    emit onIsActiveAirplaneModeChanged();
}