#ifndef AIRPLANEMODEMODEL_H
#define AIRPLANEMODEMODEL_H

#include <QObject>

class AirplaneModeModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool isAirplaneModeActive READ isAirplaneModeActive WRITE setIsAirplaneModeActive NOTIFY onIsAirplaneModeChanged)

public:
    explicit AirplaneModeModel(QObject* parent = nullptr);
    ~AirplaneModeModel();


public slots:
    bool isAirplaneModeActive() const;
    void setIsAirplaneModeActive(const bool& newStatus);

signals:
    void onIsAirplaneModeChanged();

private:
    bool m_isAirplaneModeActive {false};

};

#endif //AIRPLANEMODEMODEL_H