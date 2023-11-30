import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import "../Components"
import QML.Components

Rectangle {
    id: rootItem

    width: 500
    height: 55
    anchors.horizontalCenter: parent.horizontalCenter
    color: "transparent"

    property string beginIconSource: ""
    property string titleItemText: ""
    property string labelItemText: ""
    property string backgrBeginIconColor: ""
    property bool isHasSwitchButton: false
    property bool isEnableSeparateLine: true
    property bool switchOn: false
    property bool underlineVisible: false
    property int marginLeft: 50

    signal clicked()
    signal switchBtn()

    Rectangle {
        id: iconBeginItem
        width: 30
        height: 30
        radius: 5
        visible: rootItem.beginIconSource !== ""
        color: rootItem.backgrBeginIconColor
        anchors {
            left: rootItem.left
            leftMargin: (marginLeft - width) / 2
            verticalCenter: rootItem.verticalCenter
        }

        Image {
            id: iconImage
            width: 20
            height: 20
            source: rootItem.beginIconSource
            anchors.centerIn: parent
        }
    }

    RowLayout {
        id: row
        width: parent.width - marginLeft
        height: parent.height - (underlineVisible ? 1 : 0)
        spacing: 18

        anchors {
            left: parent.left
            leftMargin: marginLeft
        }

        Text {
            id: titleItemText
            Layout.fillHeight: true
            Layout.fillWidth: true
            visible: rootItem.titleItemText != ""
            text: rootItem.titleItemText
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font {
                pixelSize: 20
                weight: Font.Light
            }
        }

        Text {
            id: label
            Layout.fillHeight: true
            Layout.fillWidth: true
            visible: rootItem.labelItemText != ""
            text: rootItem.labelItemText
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight
            font.weight: Font.Light
        }

        SwitchButton {
            id: switchButton
            visible: isHasSwitchButton
            Layout.preferredHeight: 36
            Layout.preferredWidth: 66
            switchOn: rootItem.switchOn
            onSwitchClicked: {
                SystemSettingController.setNewAirplaneMode(!rootItem.switchOn)
            }
        }

        Icon {
            id: iconArrow
            visible: !rootItem.isHasSwitchButton
            Layout.preferredHeight: 20
            Layout.preferredWidth: 20
            source: "qrc:/Assets/arrow_right.png"
        }

        Item {
            Layout.preferredHeight: 5
            Layout.preferredWidth: 5
        }
    }

    Underline {
        marginValue: marginLeft
        visible: underlineVisible

        anchors.top: row.bottom
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        enabled: !isHasSwitchButton

        onClicked: rootItem.clicked()
    }
}
