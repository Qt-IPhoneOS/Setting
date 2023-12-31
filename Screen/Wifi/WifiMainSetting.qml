import QtQuick 2.15
import QtQuick.Controls 2.15
import Enums 1.0
import '../Common/Components'
import '../Common/Items'

RootScreen {
    id: root
    property bool switchOn: false
    contentHeight: pairedList.height + discoveryList.height

    HeaderSetting {
        width: parent.width
        backBtnText: "Setting"
        headerText: "Wi-Fi"

        onBack: ScreenNavigator.showPreviousScreen()
    }

    Rectangle {
        id: connectedArea
        width: 500
        height: WifiController.wifiOn ? 110 : 55
        radius: 15
        y: 100
        anchors.horizontalCenter: parent.horizontalCenter

        Column {
            width: parent.width
            height: parent.height

            SettingItem {
                id: wifiSwitch
                width: parent.width
                height: WifiController.wifiOn ? parent.height / 2 : parent.height
                isHasSwitchButton: true
                titleItemText: "Wi-Fi"
                switchOn: WifiController.wifiOn
                underlineVisible: WifiController.wifiOn

                onSwitchBtn: {
                    WifiController.setEnableWifi(!switchOn)
                }
            }

            DeviceItem {
                id: connectedWifi
                width: parent.width
                height: parent.height / 2
                marginLeft: 50
                textStr: WifiController.connectedName
                isConnected: WifiController.connectedStatus === Enums.DeviceConnected
                isConnecting: WifiController.connectedStatus === Enums.DeviceConnecting
                visible: WifiController.wifiOn
            }
        }
    }

    ListItemsContainer {
        id: pairedList
        y: 260
        sizeOfModel: WifiPairedModel.count
        anchors.horizontalCenter: parent.horizontalCenter
        headerText: "MY NETWORKS"
        visible: WifiController.wifiOn && sizeOfModel > 0

        listContainer: ListView {
            model: WifiPairedModel
            width: 500
            height: 55 * WifiPairedModel.count
            interactive: false
            delegate: DeviceItem {
                width: 500
                height: 55
                underlineVisible: model.index !== WifiPairedModel.count - 1
                textStr: model.name

                onDeviceClicked: {
                    if (model.name === WifiController.connectedName)
                        return

                    WifiController.connectDevice(model.addr)
                }
            }
        }
    }

    ListItemsContainer {
        id: discoveryList
        sizeOfModel: WifiDiscoveryModel.count
        headerText: "OTHER NETWORKS"
        visible: WifiController.wifiOn
        isVisibleLoadingAnimation: true

        anchors {
            horizontalCenter: parent.horizontalCenter
            top: pairedList.bottom
            topMargin: 50
        }

        listContainer: ListView {
            model: WifiDiscoveryModel
            width: 500
            height: 55 * WifiPairedModel.count
            interactive: false
            delegate: DeviceItem {
                width: 500
                height: 55
                underlineVisible: model.index !== WifiDiscoveryModel.count - 1
                textStr: model.name

                onDeviceClicked: {
                    if (model.name === WifiController.connectedName)
                        return

                    WifiController.connectDevice(model.addr)
                }
            }
        }
    }

    Component.onCompleted: {
        WifiController.startDiscovery()
    }
}
