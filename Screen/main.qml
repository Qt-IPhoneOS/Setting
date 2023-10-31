import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.VirtualKeyboard

Item {
    id: window
    width: 600; height: 900
    visible: true

    Connections {
        target: screenNavigator

        function onChangeScreen(screenId, screenStr) {
            settingPage.source = screenStr
        }
    }

    Loader {
        id: settingPage
        anchors.fill: parent
        source: "qrc:/Screen/MainSetting.qml"
    }
}
