import QtQuick 2.15
import QtQuick.Controls 2.15
import Qt5Compat.GraphicalEffects
import QtQuick.Layouts 1.15
import Enums 1.0
import QML.Components
import './Common/Components'
import './Common/Items'

ScrollScreen {
    id: rootItem

    property bool isActiveAirplaneMode: SystemSettingController.isAirplaneModeActive

    contentHeight: networkService.height

    Item {
        width: parent.width - 70
        anchors.horizontalCenter: parent.horizontalCenter

        TitleScreen {
            id: settingTitle
            width: parent.width
            height: 50
            y: 40
            anchors.horizontalCenter: parent.horizontalCenter
            textStr: "Settings"
        }

        SearchInput {
            id: searchContainer
            anchors {
                horizontalCenter: parent.horizontalCenter
                top: settingTitle.bottom
                topMargin: 10
            }
        }

        Rectangle {
            id: inforSettingContainer
            width: parent.width
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

                    Avatar {
                        id: avatarUser
                        width: 65
                        height: 65
                        sourceImg: "qrc:/Assets/avartarUser.jpg"
                    }

                    Item {
                        Layout.preferredWidth: 360
                        Layout.preferredHeight: parent.height
                        Text {
                            id: nameRect
                            width: parent.width
                            height: 40
                            text: "Monkey D. Luffy"
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
            width: parent.width

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
                            AppEngine.showScreen(Enums.SET_WifiMenu)
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
    }
}
