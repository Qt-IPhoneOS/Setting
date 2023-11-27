#ifndef SYSTEMSETTINGCONTROLLER_H
#define SYSTEMSETTINGCONTROLLER_H

#include <QObject>
#include <memory>
#include <SystemSetting/SystemSettingAdapter.h>
#include <QDebug>
#include "Model/SystemSettingModel.h"
#include <QSharedPointer>

class SystemSettingController : public QObject {
    Q_OBJECT
    Q_PROPERTY(QSharedPointer<SystemSettingModel> systemSettingModelObject READ systemSettingModelObject CONSTANT)
public:
    explicit SystemSettingController(QObject* parent = nullptr);
    ~SystemSettingController();

    inline QSharedPointer<SystemSettingModel> systemSettingModelObject() const {
        return mSystemSettingModel;
    }

public slots:
    void setNewAirplaneMode(const bool&);
    void handleUpdateAirplaneMode(const SystemSettingAdapter::AirplaneModeEnums&);

private:
    QSharedPointer<SystemSettingModel>   mSystemSettingModel;
    SystemSettingAdapter& mSysAdapter;

    signal::Connect mUpdateAirplaneMode;
};

#endif //SYSTEMSETTINGCONTROLLER_H
