import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    BusyIndicator{
        running: true;
        anchors.centerIn: parent;
        z:2
    }

}
