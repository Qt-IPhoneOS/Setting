import QtQuick 2.15
import QtQuick.Controls 2.15
import '../Components'

Item {
    id: deviceItem

    /**
      This property defines the type of a device
      true: Wifi
      false: Bluetooth
    */
    property bool isWifi: true
    property bool isConnected: false
    property bool isConnecting: false
    property int marginLeft: isWifi ? 50 : 15
    property bool underlineVisible: false
    property string textStr: ""

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

    Rectangle {
        id: area
        width: parent.width - marginLeft
        height: parent.height - (underlineVisible ? 1 : 0)
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

        Icon {
            id: circle
            width: 25
            height: 25
            visible: isWifi
            source: "qrc:/Assets/circle-i.png"

            anchors {
                verticalCenter: parent.verticalCenter
                right: parent.right
                rightMargin: 25
            }
        }

        Icon {
            id: wifi
            width: 45
            height: 45
            visible: isWifi
            source: "qrc:/Assets/wifi-strong.png"

            anchors {
                verticalCenter: parent.verticalCenter
                right: circle.left
                rightMargin: 7
            }
        }

        Icon {
            id: lock
            width: 20
            height: 20
            visible: isWifi
            source: "qrc:/Assets/lock.png"

            anchors {
                verticalCenter: parent.verticalCenter
                right: wifi.left
                rightMargin: 7
            }
        }
    }

    Underline {
        marginValue: marginLeft
        visible: underlineVisible

        anchors.top: area.bottom
    }
}
