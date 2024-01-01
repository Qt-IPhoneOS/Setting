import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import "../Components"
import QML.Components
import QML.Constants

Rectangle {
    id: rootItem
    width: 500
    height: 55

    property bool isOnlyOneItem: false

    radius: rootItem.isOnlyOneItem ? 15 : 0
    color: rootItem.isOnlyOneItem ? UIColors.white : UIColors.transparent

    anchors.horizontalCenter: parent.horizontalCenter

    property string beginIconSource: ""
    property string colorTitleText: ""
    property string titleItemText: ""
    property string labelItemText: ""
    property string backgrBeginIconColor: ""
    property bool isHasSwitchButton: false
    property bool isEnableSeparateLine: true
    property bool switchOn: false
    property bool underlineVisible: false
    property int marginLeft: 50
    property bool isShowArrowIcon: true
    property bool isPasswordItem: false

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

        CustomText {
            id: titleItemText
            Layout.fillHeight: true
            Layout.fillWidth: true
            visible: rootItem.titleItemText != ""
            textStr: rootItem.titleItemText
            fontWeight: UIFonts.medium_weight
            color: rootItem.colorTitleText
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
        }

        CustomText {
            id: label
            Layout.fillHeight: true
            Layout.fillWidth: true
            visible: rootItem.labelItemText != ""
            textStr: rootItem.labelItemText
            fontWeight: UIFonts.medium_weight
            color: UIColors.grey
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight
        }

        SwitchButton {
            id: switchButton
            visible: isHasSwitchButton
            Layout.preferredHeight: 36
            Layout.preferredWidth: 66
            switchOn: rootItem.switchOn
            onSwitched: rootItem.switchBtn()
        }

        Item {
            visible: rootItem.isPasswordItem
            Layout.preferredHeight: 20
            Layout.preferredWidth: 200
            Layout.alignment: Qt.AlignRight & Qt.AlignVCenter
            Repeater {
                anchors.fill: parent
                model: 15
                delegate: Rectangle {
                    anchors.verticalCenter: parent.verticalCenter
                    x: model.index*13
                    width: 9
                    height: 9
                    radius: 4.5
                    color: UIColors.grey
                }
            }
        }

        Icon {
            id: iconArrow
            visible: !rootItem.isHasSwitchButton && rootItem.isShowArrowIcon
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
