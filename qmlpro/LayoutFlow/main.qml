import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Flow{
        flow: Flow.TopToBottom
        spacing: 1
        Rectangle{
            width:100;
            height:50;
            border.color:"yellow"
            border.width:1
        }
        Rectangle{
            width:50;
            height:100;
            border.color:"yellow"
            border.width:1
        }
        Rectangle{
            width:50;
            height:50;
            border.color:"yellow"
            border.width:1
        }
        Rectangle{
            width:10;
            height:50;
            border.color:"yellow"
            border.width:1
        }
        Rectangle{
            width:50;
            height:10;
            border.color:"yellow"
            border.width:1
        }
        Rectangle{
            width:150;
            height:50;
            border.color:"yellow"
            border.width:1
        }
        Rectangle{
            width:50;
            height:150;
            border.color:"yellow"
            border.width:1
        }
        Rectangle{
            width:50;
            height:180;
            border.color:"yellow"
            border.width:1
        }
        Rectangle{
            width:80;
            height:50;
            border.color:"yellow"
            border.width:1
        }
    }
}
