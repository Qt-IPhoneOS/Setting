import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.VirtualKeyboard
import QML.Constants

Rectangle {
    id: mainWindow

    width: UIConstants.screen_width; height: UIConstants.screen_height
    color: UIColors.screen_background
    visible: true

    Loader {
        id: settingPage
        anchors.fill: parent
        source: ScreenSource
    }
}
