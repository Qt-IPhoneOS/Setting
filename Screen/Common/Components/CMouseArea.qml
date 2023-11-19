import QtQuick 2.15

MouseArea {
    id: rootItem

    signal press()

    signal release()

    property bool isValidEvent: false

    onPressed: (mosue)=> {
        rootItem.isValidEvent = true
        rootItem.press()
        
    }

    onReleased: (mouse)=>{
        rootItem.isValidEvent = false
        rootItem.release()
    }

}
