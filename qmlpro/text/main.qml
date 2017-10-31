import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 640
    title: qsTr("Hello World")

    Rectangle{
        anchors.centerIn: parent
        Text {
            id: mytext
            color:"blue"
            font.bold: true
            font.pixelSize: 24
            text: "Text"
            anchors.centerIn: parent
        }
    }
}
