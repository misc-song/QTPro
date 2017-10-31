import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle{
        id:bgcolor
        anchors.fill:parent
        color:"black"
    }
    MouseArea{
        id:mouseEvent
        anchors.fill:parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {
            if(mouse.button === Qt.RightButton)
            {
                Qt.quit();
            }
            else if(mouse.button === Qt.LeftButton)
            {
                bgcolor.color = Qt.rgba(Math.random(255),Math.random(255),Math.random(255),1);
            }
        }
        onDoubleClicked:
            bgcolor.color = "pink";
    }

}
