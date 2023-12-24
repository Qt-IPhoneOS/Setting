import QtQuick 2.15
import QtQuick.Controls 2.15
import QML.Constants

Rectangle {
    id: icon

    property string source: ""
    color: UIColors.transparent

    Image {
        id: connected
        anchors.fill: parent
        source: icon.source
        smooth: true
    }
}
