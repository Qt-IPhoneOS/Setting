import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.VirtualKeyboard
import QML.Constants

Item {
    id: window
    width: UIConstants.screen_width; height: UIConstants.screen_height
    visible: true

    Loader {
        id: settingPage
        anchors.fill: parent
        source: ScreenSource
    }
}
