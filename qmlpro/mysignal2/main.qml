import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle{
        id:senter
        signal sent();
        onSent:{
            console.log("what fuck");
        }
    }
    MouseArea {
        id:ms
        anchors.fill:parent
    }

    Component.onCompleted: {
        ms.clicked.connect(senter.sent);
    }
}
