#ifndef AIRPLANEMODECONTROLLER_H
#define AIRPLANEMODECONTROLLER_H

#include <QObject>
#include <memory>
#include "../../Model/AirplaneMode/AirplaneModeModel.h"

class AirplaneModeController : public QObject {
    Q_OBJECT
    Q_PROPERTY(std::shared_ptr<AirplaneModeModel> airplaneModelIns READ airplaneModelIns WRITE setAirplaneModelIns)

public:
    ~AirplaneModeController();
    static AirplaneModeController& getInstance();

    std::shared_ptr<AirplaneModeModel> airplaneModelIns() const {
        return mAirplaneModelObj;
    }

    void setAirplaneModelIns(const std::shared_ptr<AirplaneModeModel>& newObject);

private:
    std::shared_ptr<AirplaneModeModel> mAirplaneModelObj;

private: //singleton
    AirplaneModeController(std::shared_ptr<AirplaneModeModel>&);
    AirplaneModeController();
};


#endif //AIRPLANEMODECONTROLLER_H