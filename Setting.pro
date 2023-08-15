QT += quick virtualkeyboard
CONFIG += c++20

LIBS += -L$$PWD/../Executable \
        -lservice \
        -luicommon

INCLUDEPATH += $$PWD/../ServiceWrapper/include \
               $$PWD/../ServiceWrapper/include/Common \
               $$PWD/../ServiceWrapper/include/SystemSetting \
               $$PWD/../ServiceWrapper/include/SmartPhone \
               $$PWD/../Common

SOURCES += \
        AppWindow/AppMain.cpp \
        AppWindow/AppWindow.cpp \
        Common/Enums.cpp \
        Controller/WifiController.cpp \
        Interface/Wifi/WifiAdapter.cpp \
        Interface/Wifi/WifiInterface.cpp \
        main.cpp

resources.prefix = /$${TARGET}
RESOURCES += resources \
    Setting.qrc \
    Images.qrc

resources.files = Component/main.qml

HEADERS += \
    AppWindow/AppMain.h \
    AppWindow/AppWindow.h \
    Common/Enums.h \
    Controller/WifiController.h \
    Interface/Wifi/WifiInterface.h \

DISTFILES +=

