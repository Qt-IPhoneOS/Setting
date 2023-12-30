import QtQuick 2.15
import QtQuick.Controls 2.15
import Enums 1.0
import QML.Components
import '../Common/Components'
import '../Common/Items'
import QML.Components
import QML.Constants

Rectangle {
   id: rootItem
   color: UIColors.screen_background

    HeaderScreen {
        id: headerWifi
        z: 10
        backBtnText: "Setting"
        headerText: "Wi-Fi"
        onBack: AppEngine.backScreen()
    }

    RootScreen {
        id: rootScreen

        width: parent.width
        height: parent.height - headerWifi.height
        anchors.top: headerWifi.bottom

        property bool switchOn: false
        property bool isFlicked: false

        contentHeight: itemContainer.childrenRect.height + 50

        QtObject {
            id: paramsDevice
            property string deviceName: ""
            property bool isConnecting: false
            property int typeDeviceConnect: 1
            property string addressDevice: ""
        }

        Connections {
            target: WifiController
            function onSingleDeviceObjectChanged() {
                AppEngine.showScreen(Enums.SET_WifiDevice)
            }
        }

        function setDataDevice(__param) {
            paramsDevice.deviceName = __param.name
            paramsDevice.deviceName = __param.addr
        }

        Item {
            id: itemContainer
            width: parent.width

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

                        onDeviceInfoClicked: {
                            paramsDevice.typeDeviceConnect = 0
                            paramsDevice.deviceName = WifiController.connectedName
                            WifiController.sendParamsDevice(paramsDevice)
                        }
                    }
                }
            }

            QtObject {
                id: paramsWifiDevice
                property string deviceName: ""
                property bool isAutoConnect: false
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

                        onDeviceInfoClicked: {
                            paramsDevice.typeDeviceConnect = 1
                            paramsDevice.deviceName = model.name
                            paramsDevice.addressDevice = model.addr
                            WifiController.sendParamsDevice(paramsDevice)
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

                        onDeviceInfoClicked: {
                            paramsDevice.typeDeviceConnect = 2
                            paramsDevice.deviceName = model.name
                            paramsDevice.addressDevice = model.addr
                            WifiController.sendParamsDevice(paramsDevice)
                        }
                    }
                }
            }
        }

        Component.onCompleted: {
            WifiController.startDiscovery()
        }
    }
}
