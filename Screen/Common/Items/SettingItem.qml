import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import "../Components"

Rectangle {
    id: rootItem

    width: 500
    height: 55

    anchors.horizontalCenter: parent.horizontalCenter

    property string beginIconSource: ""

    property string titleItemText: ""

    property string labelItemText: ""

    property string backgrBeginIconColor: ""

    property bool isHasSwitchButton: false

    property bool isEnableSeparateLine: true

    signal clicked()

    RowLayout {
        anchors.fill: parent
        spacing: 18

        Item {
            Layout.preferredHeight: 5
            Layout.preferredWidth: 5
        }

        Rectangle {
            id: iconBeginItem
            Layout.preferredHeight: 30
            Layout.preferredWidth: 30
            radius: 5
            visible: rootItem.beginIconSource !== ""
            color: rootItem.backgrBeginIconColor
            Image {
                id: iconImage
                width: 20
                height: 20
                source: rootItem.beginIconSource
                anchors.centerIn: parent
            }
        }

        Text {
            id: titleItemText
            Layout.fillHeight: true
            Layout.fillWidth: true
            visible: rootItem.titleItemText != ""
            text: rootItem.titleItemText
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.weight: Font.Light
        }

        Text {
            id: labelItemText
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
            Layout.preferredHeight: 40
            Layout.preferredWidth: 70
            onSwitchClicked: {
                switchButton.switchOn = !switchButton.switchOn
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

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        onClicked: rootItem.clicked()
    }
}
