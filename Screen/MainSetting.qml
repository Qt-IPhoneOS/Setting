import QtQuick 2.15
import QtQuick.Controls 2.15
//import Qt5Compat.GraphicalEffects
import QtQuick.Layouts 1.15
import Enums 1.0
import './Common/Components'
import './Common/Items'

RootScreen {
    id: rootItem

    property bool isActiveAirplaneMode: SystemSettingModel.isActiveAirplaneMode

    contentHeight: networkService.height

    Text {
        id: settingTitle
        width: 500
        height: 50
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: Text.AlignLeft
        text: "Settings"
        font.pixelSize: 40
    }

    Rectangle {
        id: searchContainer
        width: 500
        height: 35
        radius: 5
        color: "#B7B7B7"
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: settingTitle.bottom
            topMargin: 10
        }
        Image {
            width: 20
            height: 20
            source: "qrc:/Assets/search_image.png"
            anchors.verticalCenter: parent.verticalCenter
            x: 10
        }
        TextInput {
            id: inputContainer
            width: 510
            height: 30
            x: 40
            anchors {
                verticalCenter: parent.verticalCenter
            }
            topPadding: 6
            color: "black"

            property string placeholderText: "Search"

            Text {
                text: inputContainer.placeholderText
                color: "#808080"
                visible: !inputContainer.length
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }

    Rectangle {
        id: inforSettingContainer
        width: 500
        height: 100
        anchors {
            top: searchContainer.bottom
            horizontalCenter: parent.horizontalCenter
            topMargin: 10
        }
        color: "white"
        radius: 15

        Item {
            height: 100
            width: parent.width
            anchors.top: parent.top
            RowLayout {
                anchors.fill: parent
                Item {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                Image {
                    id: avatarUser
                    width: 65
                    height: 65
                    Layout.preferredWidth: 65
                    Layout.preferredHeight: 65
                    source: "qrc:/Assets/avartarUser.jpg"
                    layer.enabled: true
//                        layer.effect: OpacityMask {
//                            id: mask
//                            maskSource: Rectangle {
//                                width: avatarUser.width
//                                height: avatarUser.height
//                                anchors.centerIn: parent
//                                radius: avatarUser.width/2
//                            }
//                        }
                }
                Item {
                    Layout.preferredWidth: 360
                    Layout.preferredHeight: parent.height
                    Text {
                        id: nameRect
                        width: parent.width
                        height: 40
                        text: "Yua Mikami"
                        anchors.top: parent.top
                        anchors.topMargin: 25
                        font.pixelSize: 20
                    }
                    Text {
                        id: content
                        width: parent.width
                        height: 20
                        anchors.top: nameRect.bottom
                        text: "Apple ID, iCloud, Media & Purchases"
                        font.pixelSize: 10
                    }

                }
                Icon {
                    Layout.preferredWidth: 20
                    Layout.preferredHeight: 20
                    x: 525
                    source: "qrc:/Assets/arrow_right.png"
                }
                Item {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }
            }
        }
    }

    ListItemsContainer {
        id: networkService
        sizeOfModel: myModel.count
        width: 500

        property int wifiType: 1

        anchors {
            horizontalCenter: parent.horizontalCenter
            top: inforSettingContainer.bottom
        }

        listContainer: ListView {
            anchors.fill: parent
            spacing: 0
            model: myModel
            interactive: false
            delegate: SettingItem {
                beginIconSource: model.beginIconSrc
                titleItemText: model.titleText
                backgrBeginIconColor: model.brgColor
                labelItemText: model.labelText
                isHasSwitchButton: model.switchBtn
                switchOn: rootItem.isActiveAirplaneMode
                marginLeft: 80
                underlineVisible: model.index < myModel.count - 1

                onClicked: {
                    if (model.index === networkService.wifiType)
                    {
                        ScreenNavigator.showNextScreen(Enums.WifiMainScreen)
                    }
                }
            }
        }
    }

    ListModel {
        id: myModel
        ListElement { beginIconSrc: "qrc:/Assets/wifi.png";       titleText: "Airplane Model";    brgColor: "#FF9400";  labelText: "";  switchBtn: true }
        ListElement { beginIconSrc: "qrc:/Assets/wifi.png";       titleText: "Wi-Fi";             brgColor: "#007BFF";  labelText: "SH3 P303";  switchBtn: false }
        ListElement { beginIconSrc: "qrc:/Assets/bluetooth.png";  titleText: "Bluetooth";         brgColor: "#0370F9";  labelText: "Off";  switchBtn: false }
        ListElement { beginIconSrc: "qrc:/Assets/bluetooth.png";  titleText: "Cellular";          brgColor: "#34C55F";  labelText: "On";  switchBtn: false }
        ListElement { beginIconSrc: "qrc:/Assets/bluetooth.png";  titleText: "Personal Hotspot";  brgColor: "#007BFF";  labelText: "Off";  switchBtn: false }
    }
    //
}
