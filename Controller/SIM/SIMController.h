#ifndef SIMCONTROLLER_H
#define SIMCONTROLLER_H

#include <SIM/SIMAdapter.h>
#include <QObject>

class SIMController : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool isCellularStatus READ isCellularStatus WRITE setisCellularStatus NOTIFY onisCellularStatusChanged)
    Q_PROPERTY(bool isEnableJoinNetwork READ isEnableJoinNetwork WRITE setIsEnableJoinNetwork NOTIFY onIsEnableJoinNetworkChanged)
    Q_PROPERTY(bool isMaximizeCompatibility READ isMaximizeCompatibility WRITE setIsMaximizeCompatibility NOTIFY onIsMaximizeCompatibilityChanged)

public:
    SIMController(QObject* parent = nullptr);
    ~SIMController();

public slots:
    void handleUpdateDataSIMService(midlayer::SIMAdapter::ID_CALLBACK idEvent, const int& dataEvent);

public:
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
    void onisCellularStatusChanged();
    void onIsEnableJoinNetworkChanged();
    void onIsMaximizeCompatibilityChanged();

private:
    midlayer::SIMAdapter& mSIMAdapter;

    uicommon::Connect mUpdateDataSIMService;
    bool m_isCellularStatus {false};
    bool m_isEnableJoinNetwork {false};
    bool m_isMaximizeCompatibility {false};
};

#endif //SIMCONTROLLER_H
