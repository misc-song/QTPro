import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    width: 640;
    height:480;
    RowLayout {
        id: rrow1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 80
        anchors.top: parent.top
        Label {
            id: userNameLabel
            text: "账    号:"
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
        id: rrow2
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 60
        anchors.top: rrow1.top
        Label {
            id: ruserPasswdLabel
            text: "密    码:"
            font.pixelSize: 25
        }

        TextField {
            id: userpasswd
            echoMode: TextField.Password
            font.pixelSize: 25
            Layout.minimumWidth: 200
        }
    }
    RowLayout {
        id: rrow3
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 60
        anchors.top: rrow2.top
        Label {
            id: ruserPasswdRepeatLabel
            text: "确认密码:"
            font.pixelSize: 25
        }

        TextField {
            id: userpasswdrepeat
            echoMode: TextField.Password
            font.pixelSize: 25
            Layout.minimumWidth: 200
        }
    }
    RowLayout {
        id: rrow4
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 70
        anchors.top: rrow3.top
        Button {
            id: button2
            text: qsTr("注    册")
            Layout.minimumWidth: 200
        }
    }
}
