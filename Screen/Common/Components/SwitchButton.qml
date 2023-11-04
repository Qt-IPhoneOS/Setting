import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: switchContainer
    width: 70
    height: 36
    color: "transparent"
    property bool switchOn: false

    signal switchClicked()

    Rectangle {
        width: parent.width
        height: parent.height
        radius: parent.height / 2
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        clip: true
        color: switchContainer.switchOn ? "#4CD964" : "#E5E5E5"

        Rectangle {
            width: 34
            height: 34
            radius: width / 2
            color: "white"
            border.color: "#E5E5E5"
            anchors.verticalCenter: parent.verticalCenter
            x: switchContainer.switchOn ? parent.width - width - 2 : 2
            Behavior on x {
                NumberAnimation { duration: 200 }
            }
        }

        MouseArea {
            id: switchArea
            width: parent.width
            height: parent.height
            onClicked: switchContainer.switchClicked()
        }
    }
}


