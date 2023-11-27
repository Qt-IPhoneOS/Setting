import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: loadingBg
    color: "transparent"
    width: 20
    height: 20

    property int duration: 800

    Image {
        id: loadingImg
        anchors.fill: parent
        opacity: 0.5
        source: "qrc:/Assets/loading-img.png"

        NumberAnimation on rotation{
            from: 0
            to: 360
            loops: Animation.Infinite
            duration: 1500
        }
    }
}
