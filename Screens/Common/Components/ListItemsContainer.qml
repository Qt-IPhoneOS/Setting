import QtQuick 2.15
import QtQuick.Controls 2.15
import './'
import QML.Components
import QML.Constants

Item {
    id: container
    width: 500
    height: 55 * sizeOfModel + 25

    property Component listContainer: undefined
    property int sizeOfModel
    property string headerText: ""

    property bool isVisibleLoadingAnimation: false


    QtObject {
        id: constantListItemContainer

    }

    CustomText {
        id: text
        x: 15
        color: UIColors.medium_light_gray
        textStr: headerText
        visible: headerText !== ""
        font {
            pixelSize: 15
            weight: Font.Light
        }
    }

    LoadingAnimation {
        anchors {
            left: text.right
            leftMargin: 10
        }
        visible: container.isVisibleLoadingAnimation
    }

    Rectangle {
        radius: 15
        width: parent.width
        height: 55 * sizeOfModel
        color: UIColors.white
        anchors {
            top: text.bottom
            topMargin: 12
        }

        Loader {
            id: loader
            anchors.fill: parent
            sourceComponent: listContainer
        }
    }
}


