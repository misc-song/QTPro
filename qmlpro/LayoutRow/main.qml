import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Row{
        //layoutDirection: // Qt.RightToLeft从右向左 Qt.LeftToRight 从左向右
        anchors.top: parent.top
        anchors.topMargin: 2
        anchors.left: parent.left
        anchors.leftMargin: 2
        spacing: 2
        Rectangle{
            id:rect1;
            width:25;
            height:25;
            border.color: "blue"
            border.width: 1;
        }
        Rectangle{
            id:rect2;
            width:25;
            height:25;
            border.color: "blue"
            border.width: 1;
        }
        Rectangle{
            id:rect3;
            width:25;
            height:25;
            border.color: "blue"
            border.width: 1;
        }
        Rectangle{
            id:rect4;
            width:25;
            height:25;
            border.color: "blue"
            border.width: 1;
        }
        Rectangle{
            id:rect5;
            width:25;
            height:25;
            border.color: "blue"
            border.width: 1;
        }
        Rectangle{
            id:rect6;
            width:25;
            height:25;
            border.color: "blue"
            border.width: 1;
        }
        Rectangle{
            id:rect7;
            width:25;
            height:25;
            border.color: "blue"
            border.width: 1;
        }
    }

}
