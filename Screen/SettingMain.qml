import QtQuick 2.15
import QtQuick.Controls 2.15
import Qt5Compat.GraphicalEffects
import './Common/Components'
import './Common/Items'

Rectangle {
    id: rootItem
    width: 550
    height: 1100
    color: "#f0f2f5"

    Flickable {
        id: flickItem
        width: parent.width
        height: parent.height
        contentWidth: parent.width
        contentHeight: firstListItem.height

        Text {
            id: settingTitle
            width: 510
            height: 50
            anchors {
                top: parent.top
                left: parent.left
                leftMargin: 20
            }
            text: "Settings"
            font.pixelSize: 40
        }

        Rectangle {
            id: searchContainer
            width: parent.width - 40
            height: 35
            radius: 7
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
            width: rootItem.width - 40
            height: 160
            radius: 15
            anchors {
                top: searchContainer.bottom
                horizontalCenter: parent.horizontalCenter
                topMargin: 10
            }
            color: "white"

            Rectangle {
                id: inforContainer
                width: parent.width
                height: 100
                radius: 15
                anchors.top: parent.top
                color: mouseName.pressed ? "#B7B7B7" : "white"
                Image {
                    id: avatarUser
                    width: 65
                    height: 65
                    x: 20
                    anchors.verticalCenter: parent.verticalCenter
                    source: "qrc:/Assets/avartarUser.jpg"
                    layer.enabled: true
                    layer.effect: OpacityMask {
                        id: mask
                        maskSource: Rectangle {
                            width: avatarUser.width
                            height: avatarUser.height
                            anchors.centerIn: parent
                            radius: avatarUser.width/2
                        }
                    }
                }
                Text {
                    id: nameRect
                    text: "Yua Mikami"
                    x: 100
                    y: 20
                    font.pixelSize: 20
                }
                Text {
                    id: content
                    text: "Apple ID, iCloud, Media & Purchases"
                    x: 100
                    y: 55
                    font.pixelSize: 10
                }
                Icon {
                    width: 20
                    height: 20
                    anchors.verticalCenter: parent.verticalCenter
                    x: 525
                    source: "qrc:/Assets/arrow_right.png"
                }
                Rectangle {
                    id: rec1
                    height: inforContainer.radius
                    width: inforContainer.width
                    anchors.bottom: inforContainer.bottom
                    color: inforContainer.color
                }

                CMouseArea {
                    id: mouseName
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: lineSeperate
                width: 400
                height: 1
                radius: 1
                z: 1
                anchors {
                    top: inforUpdateContainer.top
                    right: inforUpdateContainer.right
                    rightMargin: 2
                }
                color: "#f0f2f5"
            }

            Rectangle {
                id: inforUpdateContainer
                width: parent.width
                height: parent.height - inforContainer.height
                radius: 15
                anchors.top: inforContainer.bottom
                color: mouseUpdate.isValidEvent ? "#B7B7B7" :  "white"
                Text {
                    text: "IPhone Not Backed up"
                    anchors.verticalCenter: parent.verticalCenter
                    x: 20
                }
                Rectangle {
                    id: countToUpdate
                    width: 25
                    height: 25
                    x: 475
                    radius: 25/2
                    anchors.verticalCenter: parent.verticalCenter
                    color: "red"
                    Text {
                        text: "1"
                        anchors.centerIn: parent
                    }
                }
                Icon {
                    width: 20
                    height: 20
                    x: 525
                    source: "qrc:/Assets/arrow_right.png"
                    anchors.verticalCenter: parent.verticalCenter
                }
                Rectangle {
                    height: inforUpdateContainer.radius
                    width: inforUpdateContainer.width
                    anchors {
                        top: inforUpdateContainer.top
                        left: inforUpdateContainer.left
                    }
                    color: mouseUpdate.isValidEvent ? "#B7B7B7" :  "white"
                }
                CMouseArea {
                    id: mouseUpdate
                    anchors.fill: parent
                }
            }
        }
        
        Rectangle {
            id: firstListItem
            width: rootItem.width - 40
            height: myListView.count * 60
            color: "white"
            radius: 10
            anchors {
                top: inforSettingContainer.bottom
                horizontalCenter: parent.horizontalCenter
                topMargin: 10
            }

            ListModel {
                id: myModel
                ListElement { imgSrc: "qrc:/Assets/wifi.png";       brgColor: "#0370F9";   textTile: "Wi-Fi";              crnModeTxt: "Off";      switchBtn: false }
                ListElement { imgSrc: "qrc:/Assets/bluetooth.png";  brgColor: "#007BFF";   textTile: "Bluetooth";          crnModeTxt: "Off";      switchBtn: false }
            }

            ListView {
                id: myListView
                anchors.fill: parent 
                model: myModel
                interactive: false
                header: ElementComponent {
                        id: headerContainer
                        radius: 10
                        width: parent.width
                        height: 60
                        iconImgSrc: "qrc:/Assets/airplane.png"
                        backgroundColorIcon: "#FF9400"
                        itemTitleText: "Airplane Mode"
                        cunrrentModeText: "SH3 P304"
                        isSwitchBtn: trues
                        Rectangle {
                            width: parent.width
                            height: parent.radius
                            anchors.bottom: parent.bottom 
                            color: headerContainer.color
                        }
                    }


                delegate: ElementComponent {
                    width: parent.width
                    height: 60
                    iconImgSrc: model.imgSrc
                    backgroundColorIcon: model.brgColor
                    itemTitleText: model.textTile
                    cunrrentModeText: model.crnModeTxt
                    isSwitchBtn: model.switchBtn
                }

                footer: ElementComponent {
                    id: footerContainer
                    radius: 10
                    isEnableSeparateLine: false
                    width: parent.width
                    height: 60
                    iconImgSrc: "qrc:/Assets/cellular.png"
                    backgroundColorIcon: "#34C55F"
                    itemTitleText: "Personal Hotspot"
                    cunrrentModeText: "Off"
                    isSwitchBtn: false

                        Rectangle {
                            width: parent.width
                            height: parent.radius
                            anchors.top: parent.top 
                            color: footerContainer.color
                        }
                    }
            }
        }
    }
}
