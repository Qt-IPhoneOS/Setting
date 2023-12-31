import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import '../Components'

Rectangle {
    id: deviceItem

    color: "transparent"

    property bool isWifi: true
    property bool isConnected: false
    property bool isConnecting: false
    property int marginLeft: isWifi ? 50 : 15
    property bool underlineVisible: false
    property string textStr: ""

    signal deviceClicked()

    Icon {
        x: 15
        width: 20
        height: 20
        visible: isWifi && isConnected
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/Assets/connected.png"
    }

    LoadingAnimation {
        x: 15
        anchors.verticalCenter: parent.verticalCenter
        visible: isConnecting
    }

    RowLayout {
        id: area
        width: parent.width - marginLeft
        height: parent.height - (underlineVisible ? 1 : 0)
        spacing: 12

        anchors {
            left: parent.left
            leftMargin: marginLeft
        }

        Text {
            id: text
            color: "#000"
            Layout.fillHeight: true
            Layout.fillWidth: true
            text: textStr
            verticalAlignment: Text.AlignVCenter
            font {
                pixelSize: 20
                weight: Font.Light
            }
        }

        Icon {
            id: lock
            Layout.preferredHeight: 20
            Layout.preferredWidth: 20
            visible: isWifi
            source: "qrc:/Assets/lock.png"
        }

        Icon {
            id: wifi
            Layout.preferredHeight: 45
            Layout.preferredWidth: 45
            visible: isWifi
            source: "qrc:/Assets/wifi-strong.png"
        }

        Icon {
            id: circle
            Layout.preferredHeight: 25
            Layout.preferredWidth: 25
            visible: isWifi
            source: "qrc:/Assets/circle-i.png"
            z: 10
        }

        Item {
            Layout.preferredHeight: 5
            Layout.preferredWidth: 5
        }
    }

    Underline {
        marginValue: marginLeft
        visible: underlineVisible

        anchors.top: area.bottom
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        z: 1

        onClicked: deviceClicked()
    }
}
