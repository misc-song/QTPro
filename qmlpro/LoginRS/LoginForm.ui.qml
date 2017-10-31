import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    //property alias name: value
    width: 640
    height: 480
    RowLayout {
        id: row1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 100
        anchors.top: parent.top


        Label {
            id: userNameLabel
            text: "账   号:"
            font.pixelSize: 25
        }
        TextField {
            id: lusername
            echoMode: TextField.Normal
            font.pixelSize: 25
            Layout.minimumWidth: 200
        }
    }
    RowLayout {
        id: row2
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 60
        anchors.top: row1.top
        Label {
            id: luserPasswdLabel
            text: "密   码:"
            font.pixelSize: 25
        }

        TextField {
            id: luserpasswd
            echoMode: TextField.Password
            font.pixelSize: 25
            Layout.minimumWidth: 200
        }
    }
    RowLayout {
        id: row3
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 70
        anchors.top: row2.top
        Button {
            id: button1
            text: qsTr("登    录")
            Layout.minimumWidth: 200
        }
    }
}

