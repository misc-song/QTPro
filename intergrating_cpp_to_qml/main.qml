import QtQuick 2.8
import QtQuick.Controls 2.0
import QtQuick.Window 2.2
import io.qt.examples.backend 1.0
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    BackEnd {
        id: backend
        onUserNameChanged:{
            console.log(backend.userName)
        }
    }

    TextField {
        text: backend.userName
        placeholderText: qsTr("User name")
        anchors.centerIn: parent

        onTextChanged: backend.userName = text
    }
}
