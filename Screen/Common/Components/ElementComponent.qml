import QtQuick 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: rootItem

    property string iconImgSrc: ""

    property string backgroundColorIcon: ""

    property string itemTitleText: ""

    property string cunrrentModeText: ""

    property bool isSwitchBtn: false

    property bool isEnableSeparateLine: true

    color: mouseArea.isValidEvent ? "#B7B7B7" : "white"

    Rectangle {
        id: iconImage
        width: 30
        height: 30
        x: 10
        anchors.verticalCenter: parent.verticalCenter
        radius: 5
        color: rootItem.backgroundColorIcon
        Image {
            width: 20
            height: 20
            anchors.centerIn: parent
            source: rootItem.iconImgSrc
        }
    }
    
    Text {
        id: titleElement
        text: rootItem.itemTitleText
        x: 50
        anchors.verticalCenter: parent.verticalCenter
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
    }

    Text {
        id: currentMode
        text: rootItem.cunrrentModeText
        width: 100
        height: 30
        x: rootItem.isSwitchBtn ? 340 : 405
        anchors.verticalCenter: parent.verticalCenter
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignRight
    }

    SwitchButton {
        id: switchBtn
        x: 460
        visible: rootItem.isSwitchBtn
        anchors.verticalCenter: parent.verticalCenter
    }

    Icon {
        width: 20
        height: 20
        x: 520
        anchors.verticalCenter: parent.verticalCenter
        visible: !rootItem.isSwitchBtn
        source: "qrc:/Assets/arrow_right.png"

    }

    Rectangle {
        id: lineSeperate
        visible: rootItem.isEnableSeparateLine
        width: 400
        height: 1
        color: mouseArea.isValidEvent ? "#B7B7B7" : "#f0f2f5"
        radius: 1
        z: 1
        anchors {
            bottom: parent.bottom
            right: parent.right
        }
    }

    CMouseArea {
        id: mouseArea
        anchors.fill: parent
        onReleased: {
            switchBtn.switchOn = !switchBtn.switchOn
        }
    }
}
