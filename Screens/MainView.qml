import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.VirtualKeyboard
import QML.Constants

Rectangle {
    id: mainWindow

    width: UIConstants.screen_width; height: UIConstants.screen_height
    color: UIConstants.screen_background_color
    visible: true

    Loader {
        id: settingPage
        anchors.fill: parent
        source: ScreenSource
        onSourceChanged: {
            console.log("\n---> SOURCE: " + settingPage.source)
        }
    }
}
