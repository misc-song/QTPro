import QtQuick 2.8
import QtQuick.Window 2.2
import an.qt.ColorMaker 1.0
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
Rectangle{
    height:300;
    width:400;
    ColorMaker{
        color: Qt.green;
    }
}
}
