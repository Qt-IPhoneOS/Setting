#ifndef ENUMS_H
#define ENUMS_H

#include <QObject>

class Enums : public QObject {
    Q_OBJECT
public:
    Enums();

    enum class HMI_VIEW {
        HMI_VIEW_NONE,
        HMI_VIEW_HOME
    };

    Q_ENUM(HMI_VIEW)
};

#endif // ENUMS_H
