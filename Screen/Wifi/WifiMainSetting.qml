import QtQuick 2.15
import QtQuick.Controls 2.15
import Enums 1.0
import '../Common/Components'
import '../Common/Items'

Rectangle {
    id: root
    width: 550; height: 1100
    color: "#f0f2f5"
    property bool switchOn: false

    HeaderSetting {
        width: parent.width
        backBtnText: "Setting"
        headerText: "Wi-Fi"

        onBack: screenNavigator.showPreviousScreen()
    }

    Rectangle {
        id: connectedArea
        width: 500
        height: wifiController.wifiOn ? 110 : 55
        radius: 15
        y: 100
        anchors.horizontalCenter: parent.horizontalCenter

        Column {
            width: parent.width
            height: parent.height

            SettingItem {
                id: wifiSwitch
                width: parent.width
                height: wifiController.wifiOn ? parent.height / 2 : parent.height
                isHasSwitchButton: true
                titleItemText: "Wi-Fi"
                switchOn: wifiController.wifiOn
                underlineVisible: wifiController.wifiOn

                onSwitchBtn: {
                    wifiController.setEnableWifi(!switchOn)
                }
            }

            DeviceItem {
                id: connectedWifi
                width: parent.width
                height: parent.height / 2
                marginLeft: 50
                textStr: wifiController.connectedName
                isConnected: wifiController.connectedStatus === Enums.DeviceConnected
                isConnecting: wifiController.connectedStatus === Enums.DeviceConnecting
                visible: wifiController.wifiOn
            }
        }
    }

    ListItemsContainer {
        id: pairedList
        y: 260
        sizeOfModel: wifiDeviceModel.count
        anchors.horizontalCenter: parent.horizontalCenter
        headerText: "MY NETWORKS"
        visible: wifiController.wifiOn

        listContainer: ListView {
            model: wifiDeviceModel
            width: 500
            height: 55 * wifiDeviceModel.count
            interactive: false
            delegate: DeviceItem {
                width: 500
                height: 55
                underlineVisible: model.index !== wifiDeviceModel.count - 1
                textStr: model.name

                onDeviceClicked: {
                    wifiController.connectDevice(model.addr)
                }
            }
        }
    }

    ListItemsContainer {
        id: discoveryList
        sizeOfModel: 2
        headerText: "OTHER NETWORKS"
        visible: wifiController.wifiOn
        isVisibleLoadingAnimation: true

        anchors {
            horizontalCenter: parent.horizontalCenter
            top: pairedList.bottom
            topMargin: 50
        }

        listContainer: ListView {
            model: 2
            anchors.fill: parent
            interactive: false
            delegate: Rectangle {
                width: parent.width
                height: 55
                color: "transparent"
                DeviceItem {
                    anchors.fill: parent
                    underlineVisible: model.index !== 1
                    marginLeft: 50
                    textStr: "Anh Ha"
                }
            }
        }
    }
}
