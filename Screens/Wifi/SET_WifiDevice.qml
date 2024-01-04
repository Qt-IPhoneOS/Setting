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

    QtObject {
        id: privDevice
        property bool isAutoJoin: false
        property bool isLowDataMode: false
        property bool isPrivateWifiAddress: false
    }

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
                Layout.preferredHeight: 12
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
                Layout.preferredHeight: 12
                Layout.preferredWidth: parent.width
                visible: __infoDevice.typeDeviceConnect == 0 || __infoDevice.typeDeviceConnect == 1
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
                            if (model.index === 0) return "Auto-Join"
                            else return "Password"
                        }
                        isHasSwitchButton: model.index === 0
                        isPasswordItem: model.index === 1
                        onSwitchBtn: privDevice.isAutoJoin = !privDevice.isAutoJoin
                        switchOn: privDevice.isAutoJoin
                    }
                }
            }
            Item {
                visible: __infoDevice.typeDeviceConnect != 2
                Layout.preferredHeight: 12
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
                    onSwitchBtn: privDevice.isLowDataMode = !privDevice.isLowDataMode
                    switchOn: privDevice.isLowDataMode
                }
            }
            Item {
                Layout.preferredHeight: 12
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
                            if (model.index === 0) return "Private Wi-Fi Address"
                            else return "Wi-Fi Address"
                        }
                        labelItemText: {
                            if (model.index === 1) return __infoDevice.addressDevice
                            else return ""
                        }
                        isHasSwitchButton: model.index === 0
                        onSwitchBtn: privDevice.isPrivateWifiAddress = !privDevice.isPrivateWifiAddress
                        switchOn: privDevice.isPrivateWifiAddress
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
