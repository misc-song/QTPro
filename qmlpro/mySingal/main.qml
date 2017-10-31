import QtQuick 2.2
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
Window {
    visible: true
    width: 640
    height: 480
    color: "#C0C0C0"
    Text {
        id: coloredText
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top:parent.top
        anchors.topMargin: 4;
        text:"hello world";
        font.pixelSize: 32;
    }
    Component{
        id:colorComponent
        Rectangle{
            id:colorPicker
            width:50;
            height:30;
            signal colorPicked(color clr);
            MouseArea{
                anchors.fill:parent
                onPressed: colorPicker.colorPicked(colorPicker.color);
            }
        }
    }
    Loader{
        id: redLoader
        anchors.left: parent.left
        anchors.leftMargin: 4;
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 4;
        sourceComponent: colorComponent;
        onLoaded: {
            item.color = "red";
        }
    }
    Loader{
        id: blueLoader
        anchors.left: parent.left
        anchors.leftMargin: 4;
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 4;
        sourceComponent: colorComponent;
        onLoaded: {
            item.color = "blue";
        }
    }
    Connections{
        target: redLoader.item
        onColorPicked:{
            coloredText.color = clr;
        }
    }
    Connections{
        target: blueLoader.item
        onColorPicked:{
            colorredText.color = clr;
        }
    }

}
