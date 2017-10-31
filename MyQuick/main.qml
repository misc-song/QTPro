import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
import Qt.labs.platform 1.0


Window {
    id: window
    visible: true
    width: 640
    height: 480
    property alias tabBar: tabBar
    title: qsTr("My Quick")

    TabBar {
        id: tabBar
        x: 0
        y: 1
        width: 640
        height: 40

        TabButton {
            id: tabButton
            text: qsTr("Tab Button")
            spacing: 1
        }

        TabButton {
            id: tabButton1
            text: qsTr("Tab Button")
            spacing: 1
        }

        TabButton {
            id: tabButton3
            text: qsTr("Tab Button")
            spacing: 1
        }

        TabButton {
            id: tabButton4
            text: qsTr("Tab Button")
            spacing: 1
            enabled: true
            down: false
        }

        TabButton {
            id: tabButton2
            text: qsTr("Tab Button")
        }

        TabButton {
            id: tabButton5
            text: qsTr("Tab Button")
        }
    }

    StackLayout {
        id: stackLayout
        x: 0
        y: 54
        width: 640
        height: 426
       currentIndex: tabBar.currentIndex

        Item {
            Rectangle{
                Grid {
                    id: grid3
                    width: stackLayout.width
                    height: stackLayout.height
                    rows: 3
                    columns: 1

                    Grid {
                        id: grid
                        width: 317
                        height: 56
                        anchors.horizontalCenterOffset: 1
                        anchors.top: parent.top
                        anchors.topMargin: 80
                        anchors.horizontalCenter: parent.horizontalCenter
                        rows: 1
                        columns: 2

                        Label {
                            id: label
                            text: qsTr("UserName")
                            anchors.verticalCenter: parent.verticalCenter
                            font.pointSize: 14
                            anchors.top: parent.top
                            anchors.topMargin: 16
                        }

                        TextField {
                            id: textField
                            text: qsTr("Text Field")
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: parent.left
                            anchors.leftMargin: 100
                        }
                    }

                    Grid {
                        id: grid1
                        width: 317
                        height: 56
                        anchors.top: parent.top
                        anchors.topMargin: 160
                        anchors.horizontalCenterOffset: 1
                        anchors.horizontalCenter: parent.horizontalCenter
                        columns: 2
                        rows: 1
                        Label {
                            id: label1
                            text: qsTr("Password")
                            anchors.verticalCenter: parent.verticalCenter
                            font.pointSize: 14
                            anchors.topMargin: 16
                            anchors.top: parent.top
                        }

                        TextField {
                            id: textField1
                            text: qsTr("Text Field")
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.leftMargin: 100
                            anchors.left: parent.left
                        }
                    }

                    Grid {
                        id: grid2
                        width: 317
                        height: 56
                        anchors.top: parent.top
                        anchors.topMargin: 240
                        anchors.horizontalCenter: parent.horizontalCenter
                        rows: 2
                        columns: 1

                        Button {
                            id: button
                            text: qsTr("Login")
                            anchors.verticalCenter: parent.verticalCenter
                        }

                        Button {
                            id: button1
                            text: qsTr("Cancle")
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: parent.left
                            anchors.leftMargin: 150
                        }
                    }
                }

            }


        }

        Item {
            Button{
                width:100
                height:30
                text:"click me"
                onClicked: fileDialog.open()
            }
        }

        Item {
        }
    }
    FileDialog {
         id: fileDialog

         folder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)
     }



}


