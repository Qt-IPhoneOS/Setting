import QtQuick 2.15
import QtQuick.Controls 2.15
import Enums 1.0
import QtQml
import QtQuick.Layouts
import '../Common/Components'
import '../Common/Items'
import QML.Components
import QML.Constants

Rectangle {
    id: rootItem
    color: UIColors.screen_background

    QtObject {
        id: __infoDevice
        property string deviceName: ""
        property bool isConnecting: false
        property int typeDeviceConnect: 0
        property string addressDevice: ""
    }

    property bool isUnderLineVisible: false

    Component.onCompleted: {
        // Set information for the device
        __infoDevice.deviceName = WifiController.singleDeviceObject.deviceName
        __infoDevice.isConnecting = WifiController.singleDeviceObject.isConnecting
        __infoDevice.typeDeviceConnect = WifiController.singleDeviceObject.typeDeviceConnect
        __infoDevice.addressDevice = WifiController.singleDeviceObject.addressDevice
        console.log("Device Info - name: " + __infoDevice.deviceName
                    + " - isConnect: " + __infoDevice.isConnecting
                    + " - type: " + __infoDevice.typeDeviceConnect
                    + " - address: " + __infoDevice.addressDevice)
    }

    HeaderScreen {
        id: headerContainer
        backBtnText: "Wi-Fi"
        isFlick: rootItem.isUnderLineVisible
        headerText: __infoDevice.deviceName
        z: 10
        onBack: {
            AppEngine.backScreen()
        }
    }

    RootScreen {
        id: rootSreen
        width: parent.width
        height: parent.height - headerContainer.height
        anchors.top: headerContainer.bottom
        contentHeight: itemContainer.implicitHeight

        onVerticalVelocityChanged: {
            if (visibleArea.yPosition > 0) {
                rootItem.isUnderLineVisible = true
            } else {
                rootItem.isUnderLineVisible = false
            }
        }

        ColumnLayout {
            id: itemContainer
            width: parent.width
            spacing: 0
            ListItemsContainer {
                sizeOfModel: 1
                Layout.alignment: Qt.AlignHCenter
                visible: __infoDevice.typeDeviceConnect == 1 || __infoDevice.typeDeviceConnect == 2
                listContainer: SettingItem {
                    id: joinNetworkSection
                    isShowArrowIcon: false
                    titleItemText: "Join This Network"
                    colorTitleText: UIColors.color_highlight_text
                }
            }
            Item {
                Layout.preferredHeight: 20
                Layout.preferredWidth: parent.width
            }
            ListItemsContainer {
                sizeOfModel: 1
                visible: __infoDevice.typeDeviceConnect == 0 || __infoDevice.typeDeviceConnect == 1
                Layout.alignment: Qt.AlignHCenter
                listContainer: SettingItem {
                    id: forgetNetworkSection
                    isShowArrowIcon: false
                    titleItemText: "Forget This Network"
                    colorTitleText: UIColors.color_highlight_text
                }
            }
            Item {
                Layout.preferredHeight: 20
                Layout.preferredWidth: parent.width
            }
            ListItemsContainer {
                visible: __infoDevice.typeDeviceConnect != 2
                Layout.alignment: Qt.AlignHCenter
                sizeOfModel: 2
                listContainer: ListView {
                    interactive: false
                    model: 2
                    delegate: SettingItem {
                        underlineVisible: model.index === 0
                        isShowArrowIcon: false
                        titleItemText: {
                            if (model.index == 0) return "Auto-Join"
                            else return "Password"
                        }
                        isHasSwitchButton: model.index == 0
                        isPasswordItem: model.index == 1
                    }
                }
            }
            Item {
                visible: __infoDevice.typeDeviceConnect != 2
                Layout.preferredHeight: 20
                Layout.preferredWidth: parent.width
            }
            ListItemsContainer {
                sizeOfModel: 1
                Layout.alignment: Qt.AlignHCenter
                visible: __infoDevice.typeDeviceConnect != 2
                listContainer: SettingItem {
                    id: lowDataModeItem
                    isShowArrowIcon: false
                    isHasSwitchButton: true
                    titleItemText: "Low Data Mode"
                }
            }
            Item {
                Layout.preferredHeight: 20
                Layout.preferredWidth: parent.width
            }
            ListItemsContainer {
                Layout.alignment: Qt.AlignHCenter
                sizeOfModel: 2
                listContainer: ListView {
                    interactive: false
                    model: 2
                    delegate: SettingItem {
                        underlineVisible: model.index === 0
                        isShowArrowIcon: false
                        titleItemText: {
                            if (model.index == 0) return "Private Wi-Fi Address"
                            else return "Wi-Fi Address"
                        }
                        labelItemText: {
                            if (model.index == 1) return __infoDevice.addressDevice
                            else return ""
                        }
                        isHasSwitchButton: model.index == 0
                    }
                }
            }

            Item {
                Layout.preferredHeight: 30
                Layout.preferredWidth: parent.width
            }
            ListItemsContainer {
                Layout.alignment: Qt.AlignHCenter
                headerText: "IPV4 ADDRESS"
                sizeOfModel: 1
                visible: __infoDevice.typeDeviceConnect == 2
                listContainer: ListView {
                    interactive: false
                    model: 1
                    delegate: SettingItem {
                        titleItemText: "Configure IP"
                        labelItemText: "Automatic"
                        isShowArrowIcon: true
                    }
                }
            }
            Item {
                Layout.preferredHeight: 30
                Layout.preferredWidth: parent.width
            }
            ListItemsContainer {
                Layout.alignment: Qt.AlignHCenter
                headerText: "DSN"
                visible: __infoDevice.typeDeviceConnect == 2
                sizeOfModel: 1
                listContainer: ListView {
                    interactive: false
                    model: 1
                    delegate: SettingItem {
                        titleItemText: "Configure DSN"
                        labelItemText: "Automatic"
                        isShowArrowIcon: true
                    }
                }
            }
        }
    }
}
