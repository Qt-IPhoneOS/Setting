#ifndef AIRPLANEMODECONTROLLER_H
#define AIRPLANEMODECONTROLLER_H

#include <QObject>
#include <memory>

class AirplaneModeControler : public QObject {
    Q_OBJECT
    Q_PROPERTY(std::shared_ptr<AirplaneModel> airplaneModelIns READ airplaneModelIns WRITE setAirplaneModelIns)

    AirplaneModeControler(std::shared_ptr<AirplaneModel>&);
    AirplaneModeControler();
public:
    ~AirplaneModeControler();
    static AirplaneModeControler& getInstance();

    std::shared_ptr<AirplaneModel> airplaneModelIns() const {
        return mAirplaneModelObj;
    }

    void setAirplaneModelIns(const std::shared_ptr<AirplaneModel>& newObject);

private:
    std::shared_ptr<AirplaneModel> mAirplaneModelObj;
};


#endif //AIRPLANEMODECONTROLLER_H