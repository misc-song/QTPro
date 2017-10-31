import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle{
        id:recparent
        width:parent.width
        height:parent.height
        border.color: "black"
        border.width:1

        Rectangle{
            id:rectchild0
            width:150
            height:150
            border.color: "yellow"
            border.width: 1
            anchors.left:parent.left
            anchors.leftMargin: 10
            anchors.top:parent.top
            anchors.topMargin: 20
        }
        Rectangle{
            id:rectchild1
            width:150
            height:150
            border.color: "blue"
            border.width: 1
            anchors.left: rectchild0.right
            anchors.leftMargin: 10
            anchors.top:parent.top
            anchors.topMargin: 20;


        }
        Rectangle{
            id:rectchild2
            width:150
            height:150
            border.color: "black"
            border.width: 1
            anchors.centerIn: parent


        }
    }

}
