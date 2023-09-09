QT += quick virtualkeyboard
CONFIG += c++20

LIBS += -L$$PWD/../Executable \
        -linterfacelayer \
        -luicommon \
        -lservice

INCLUDEPATH += $$PWD/../InterfaceLayer \
               $$PWD/../InterfaceLayer/Common \
               $$PWD/../InterfaceLayer/Wifi \
               $$PWD/../UICommon \
               $$PWD/../ServiceWrapper/include
               $$PWD/../ServiceWrapper/include/Common
               $$PWD/../ServiceWrapper/include/Wifi
               $$PWD/../ServiceWrapper/include/SystemSetting

SOURCES += \
        AppWindow/AppMain.cpp \
        AppWindow/AppWindow.cpp \
        Controller/WifiController.cpp \
        Model/WifiDeviceModel.cpp \
        main.cpp

resources.prefix = /$${TARGET}
RESOURCES += resources \
    Setting.qrc \
    Images.qrc

resources.files = Screen/main.qml

HEADERS += \
    AppWindow/AppMain.h \
    AppWindow/AppWindow.h \
    Controller/WifiController.h \
    Model/WifiDeviceModel.h

DISTFILES +=

