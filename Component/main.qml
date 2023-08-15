import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.VirtualKeyboard

Item {
    id: window
    width: 700; height: 900
    visible: true

    Loader {
        id: homePage
        anchors.fill: parent
        source: "qrc:/Component/SettingPage.qml"
    }
}
