#ifndef SYSTEMSETTINGCONTROLLER_H
#define SYSTEMSETTINGCONTROLLER_H

#include <QObject>
#include <memory>
#include <SystemSetting/SystemSettingAdapter.h>
#include <QDebug>
#include <QSharedPointer>

class SystemSettingController : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool isAirplaneModeActive READ isAirplaneModeActive WRITE setIsAirplaneModeActive NOTIFY isAirplaneModeActiveChanged)
public:
    explicit SystemSettingController(QObject* parent = nullptr);
    ~SystemSettingController();

public slots:
    bool isAirplaneModeActive() const;
    void setIsAirplaneModeActive(bool newIsAirplaneModeActive);

    void handleUpdateAirplaneMode(const SystemSettingAdapter::AirplaneModeEnums&);

public:
    Q_INVOKABLE void setNewValueAirplaneMode(const bool&);

signals:
    void isAirplaneModeActiveChanged();

private:
    SystemSettingAdapter& mSysAdapter;

    uicommon::Connect mUpdateAirplaneMode;
    bool m_isAirplaneModeActive {false};
};

#endif //SYSTEMSETTINGCONTROLLER_H
