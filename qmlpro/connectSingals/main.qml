import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Text {
        id: text1
        text: qsTr("text1")
        color: "blue"
        anchors.left: parent.left
        anchors.leftMargin: 5;
    }
    Text {
        id: text2
        text: qsTr("text2")
        color:"red"
        anchors.left:text1.right
        anchors.leftMargin: 5;
    }
    Text {
        id: text3
        text: qsTr("text3")
        anchors.left: text2.right
        anchors.leftMargin: 5;
    }
    Button{
        id:changeBtn
        anchors.centerIn: parent
        anchors.bottom: parent.bottom

        text:"change color"
        style:ButtonStyle{
            Rectangle{
                implicitHeight: 30;
                implicitWidth: 70;
                color:control.hovered ? "#a4a4a4" : "#a0a0a0";
                border.width: 1;
                radius: 4
            }
        }
    }
    Connections{
        target: changeBtn
        onClicked:{
            text1.color = Qt.rgba(Math.random(255),Math.random(255),Math.random(155),1);
            text2.color = Qt.rgba(Math.random(255),Math.random(255),Math.random(155),1);
            text3.color = Qt.rgba(Math.random(255),Math.random(255),Math.random(155),1);
        }

    }

}
