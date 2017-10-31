import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    FirstComp{
        id: mybtn
        text:"click me"
        anchors.centerIn: parent;
        onClicked: {
            console.log("i am clicked");
        }
    }
    BackgroudCol{
        anchors.top:parent;
        anchors.topMargin: 5;
    }
}
