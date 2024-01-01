#ifndef SYSTEMSETTINGCONTROLLER_H
#define SYSTEMSETTINGCONTROLLER_H

#include <QObject>
#include <SystemSetting/SystemSettingAdapter.h>
#include <SIM/SIMAdapter.h>

class SystemSettingController : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool isAirplaneModeActive READ isAirplaneModeActive WRITE setIsAirplaneModeActive NOTIFY isAirplaneModeActiveChanged)

public:
    explicit SystemSettingController(QObject* parent = nullptr);
    ~SystemSettingController();

public slots:
    void handleUpdateDataSystemSetting(midlayer::SystemSettingAdapter::ID_CALLBACK idEvent, const int& dataEvent);

public:
    Q_INVOKABLE void setNewValueAirplaneMode(const bool&);

    bool isAirplaneModeActive() const;
    void setIsAirplaneModeActive(bool newIsAirplaneModeActive);

signals:
    void isAirplaneModeActiveChanged();

private:
    midlayer::SystemSettingAdapter& mSysAdapter;
    uicommon::Connect mUpdateDataSystemSetting;

    bool m_isAirplaneModeActive {false};
};

#endif //SYSTEMSETTINGCONTROLLER_H
