import QtQuick 2.15
import QtQuick.Controls 2.15
import '../Components'

Item {
    id: switchItem
    property int marginLeft: 50
    property bool switchOn: false
    property bool underlineVisible: false
    property string textStr: ""

    signal switchClicked()

    Rectangle {
        id: rect
        width: parent.width - marginLeft
        height: parent.height
        x: marginLeft
        color: "transparent"

        Text {
            id: text
            color: "#000"
            text: textStr
            anchors.verticalCenter: parent.verticalCenter
            font {
                pixelSize: 20
                weight: Font.Light
            }
        }

        SwitchButton {
            id: switchBtn
            width: 70
            height: 40
            switchOn: switchItem.switchOn

            anchors {
                verticalCenter: parent.verticalCenter
                right: parent.right
                rightMargin: 25
            }

            onSwitchClicked: switchItem.switchClicked()
        }
    }

    Underline {
        marginValue: marginLeft
        visible: underlineVisible

        anchors.top: rect.bottom
    }
}
