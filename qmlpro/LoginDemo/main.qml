import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.2
Window {
    visible: true
    width: 320
    height: 240
    title: qsTr("Hello World")
    GridLayout{
        anchors.centerIn: parent
        flow: Flow.TopToBottom
        //Layout.rowSpan: 4
        GridLayout{
            columns: 2
            flow: Flow.LeftToRight

            Text {
                id: username
                text: qsTr("UserName:")
            }
            Rectangle{
                width: 100
                height:20
                border.color: "black"
                border.width: 1
                radius: 2
                TextInput{
                    id:tuname
                    maximumLength: 7
                    wrapMode:TextInput.Wrap;
                    anchors.fill:parent
                    anchors.left: parent.left
                    anchors.leftMargin: 2
                    font.pixelSize: 22
                }
            }
        }

        GridLayout{
            columns: 2
            flow: Flow.LeftToRight
            Text {
                id: userpwd
                text: qsTr("UserPawd:")
            }
            Rectangle{
                width: 100
                height:20
                border.color: "black"
                border.width: 1
                radius: 2

                TextInput{
                    id:tupwd
                    maximumLength: 7
                    wrapMode:TextInput.Wrap;
                    anchors.fill:parent
                    anchors.left: parent.left
                    anchors.leftMargin: 2
                    font.pixelSize: 22
                }
            }


        }

        GridLayout{
            columns: 2
            flow: Flow.LeftToRight
            Button{
                id:loginbtn
                text: qsTr("Login")
            }
            Button{
                id:regBtn
                text: qsTr("Register")
            }
        }
    }
}
