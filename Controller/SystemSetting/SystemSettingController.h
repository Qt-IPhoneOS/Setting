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
    Q_PROPERTY(bool isCellularStatus READ isCellularStatus WRITE setisCellularStatus NOTIFY onisCellularStatusChanged)
    Q_PROPERTY(bool isEnableJoinNetwork READ isEnableJoinNetwork WRITE setIsEnableJoinNetwork NOTIFY onIsEnableJoinNetworkChanged)
    Q_PROPERTY(bool isMaximizeCompatibility READ isMaximizeCompatibility WRITE setIsMaximizeCompatibility NOTIFY onIsMaximizeCompatibilityChanged FINAL)
public:
    explicit SystemSettingController(QObject* parent = nullptr);
    ~SystemSettingController();

public slots:
    bool isAirplaneModeActive() const;
    void setIsAirplaneModeActive(bool newIsAirplaneModeActive);

    void handleUpdateDataSystemSetting(midlayer::SystemSettingAdapter::ID_CALLBACK idEvent, const int& dataEvent);

public:
    Q_INVOKABLE void setNewValueAirplaneMode(const bool&);
    Q_INVOKABLE void setEnableOthersJoinNetwork(const bool&);
    Q_INVOKABLE void setIsCellularStatus(const bool&);
    Q_INVOKABLE void setMaximizeCompatibility(const bool&);


    bool isCellularStatus() const;
    void setisCellularStatus(bool newIsCellularStatus);

    bool isEnableJoinNetwork() const;
    void setIsEnableJoinNetwork(bool newIsEnableJoinNetwork);

    bool isMaximizeCompatibility() const;
    void setIsMaximizeCompatibility(bool newIsMaximizeCompatibility);

signals:
    void isAirplaneModeActiveChanged();

    void onisCellularStatusChanged();

    void onIsEnableJoinNetworkChanged();

    void onIsMaximizeCompatibilityChanged();

private:
    midlayer::SystemSettingAdapter& mSysAdapter;

    uicommon::Connect mUpdateDataSystemSetting;

    bool m_isAirplaneModeActive {false};
    bool m_isCellularStatus {false};
    bool m_isEnableJoinNetwork {false};
    bool m_isMaximizeCompatibility {false};
};

#endif //SYSTEMSETTINGCONTROLLER_H
