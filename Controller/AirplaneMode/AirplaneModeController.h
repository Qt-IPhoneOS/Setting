#ifndef AIRPLANEMODECONTROLLER_H
#define AIRPLANEMODECONTROLLER_H

#include <QObject>
#include <memory>
#include "Model/AirplaneMode/AirplaneModeModel.h"
#include <Setting/SettingAdapter.h>
#include <QDebug>

class AirplaneModeController : public QObject {
    Q_OBJECT
    Q_PROPERTY(AirplaneModeModel* airplaneModelIns READ airplaneModelIns CONSTANT)

public:
    ~AirplaneModeController();
    static AirplaneModeController& getInstance();

    void init();

public slots:
    AirplaneModeModel* airplaneModelIns() const {
        return mAirplaneModelObj.get();
    }

    void setNewAirplaneMode(const bool& newStatus);

public:
    void onNotifyAirplaneModeChanged(const middlewarelayer::AirplaneMode&);

private:
    std::shared_ptr<AirplaneModeModel> mAirplaneModelObj;
    SettingAdapter& mSettingAdapter;
    signal::Connect mUpdateAirplaneMode;

private: //singleton
    AirplaneModeController(const std::shared_ptr<AirplaneModeModel>&);
};

#endif //AIRPLANEMODECONTROLLER_H
