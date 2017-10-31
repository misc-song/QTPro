import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle{
        width: 70;
        height: 20;
        border.color: black;
        border.width: 1;
        TextInput{
            maximumLength: 8;
            font.pixelSize: 20;
            anchors.fill: parent;
            anchors.left: parent.left
            anchors.leftMargin: 2
        }
    }
    Rectangle{

    }

}
