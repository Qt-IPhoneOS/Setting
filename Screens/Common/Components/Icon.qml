import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: icon

    property string source: ""
    color: "transparent"

    Image {
        id: connected
        anchors.fill: parent
        source: icon.source
        smooth: true
    }
}
