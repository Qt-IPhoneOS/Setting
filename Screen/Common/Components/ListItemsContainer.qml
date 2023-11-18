import QtQuick 2.15
import QtQuick.Controls 2.15
import './'

Item {
    id: container
    width: 500
    height: 55 * sizeOfModel + 25

    property Component listContainer: undefined
    property int sizeOfModel
    property string headerText: ""

    property bool isVisibleLoadingAnimation: false

    Text {
        id: text
        x: 15
        color: "#a1a1a1"
        text: headerText
        visible: headerText !== "" && sizeOfModel > 0
        font {
            pixelSize: 16
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
        color: "#fff"
        anchors {
            top: text.bottom
            topMargin: 15
        }

        Loader {
            id: loader
            anchors.fill: parent
            sourceComponent: listContainer
        }
    }
}


