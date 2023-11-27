#ifndef SYSTEMSETTINGMODEL_H
#define SYSTEMSETTINGMODEL_H

#include <QObject>
#include <QDebug>

class SystemSettingModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool isActiveAirplaneMode READ isActiveAirplaneMode WRITE setIsActiveAirplaneMode NOTIFY onIsActiveAirplaneModeChanged)

public:
    explicit SystemSettingModel(QObject* parent = nullptr);
    ~SystemSettingModel();

    enum AirplaneMode {
        Inactive,
        Active
    };

public slots:
    bool isActiveAirplaneMode() const;
    void setIsActiveAirplaneMode(const bool& newStatus);

signals:
    void onIsActiveAirplaneModeChanged();

private:
    bool mIsActiveAirplaneMode   {true};
};

#endif //SYSTEMSETTINGMODEL_H
