import QtQuick 2.15
import QtQuick.Controls 2.15
import Qt5Compat.GraphicalEffects
import QtQuick.Layouts 1.15
import Enums 1.0
import QML.Components
import '../Common/Components'
import '../Common/Items'
import QML.Constants

Rectangle {
    id: rootItem
    color: UIColors.screen_background

    property bool isUnderLineVisible: false

    QtObject {
        id: __privCtlItem
        property string password: "11119999"
        property bool isEnableJoinNetwork: SIMController.isEnableJoinNetwork
        property bool isMaximizeCompa: SIMController.isMaximizeCompatibility
    }

    HeaderScreen {
        id: headerItem
        headerText: "Personal Hotspot"
        backBtnText: "Back"
        onBack: AppEngine.backScreen()
    }

    RootScreen {
        id: rootScreen
        width: parent.width
        height: parent.height - headerItem.height
        anchors.top: headerItem.bottom

        ListItemsContainer {
            anchors {
                horizontalCenter: parent.horizontalCenter
                top: parent.top
            }
            sizeOfModel: 2
            listContainer: ListView {
                interactive: false
                model: 2
                delegate: SettingItem {
                    isHasSwitchButton: model.index === 0 ? true : false
                    underlineVisible: model.index !== 1
                    titleItemText: model.index === 0 ? "Allow Others to Join" : "Wi-Fi Password"
                    labelItemText: model.index === 1 ? __privCtlItem.password : ""
                    onSwitchBtn: SIMController.setEnableOthersJoinNetwork(!__privCtlItem.isEnableJoinNetwork)
                    switchOn: __privCtlItem.isEnableJoinNetwork
                }
            }
        }

        SettingItem {
            anchors {
                horizontalCenter: parent.horizontalCenter
                top: parent.top
                topMargin: 170
            }
            isOnlyOneItem: true
            onSwitchBtn: SIMController.setMaximizeCompatibility(!__privCtlItem.isMaximizeCompa)
            switchOn: __privCtlItem.isMaximizeCompa
            isHasSwitchButton: true
            titleItemText: "Maximize Compatibility"
        }
    }
}
