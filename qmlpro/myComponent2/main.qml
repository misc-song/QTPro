import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Text {
        id: coloredText
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: parent.top
        anchors.topMargin: 4
        text: qsTr("text")
        font.pixelSize: 32
       // color: "red"
    }

    ColorPicker{
        id:redColor
        color: "red";
        focus: true;
        anchors.left: parent.left;
        anchors.leftMargin: 4;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 4
        KeyNavigation.right: blueColor;
        KeyNavigation.tab: blueColor;
        onColorPicked: {
            coloredText.color = clr;
        }
    }
    ColorPicker{
        id:blueColor
        color: "blue";
        focus: true;
        anchors.left: redColor.right;
        anchors.leftMargin: 4;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 4
        KeyNavigation.left: redColor;
        KeyNavigation.right: pinkColor;
        KeyNavigation.tab: pinkColor;
//        onColorPicked: {
//            coloredText.color = clr;
//        }
    }
    ColorPicker{
        id:pinkColor
        color: "pink";
        focus: true;
        anchors.left: blueColor.right;
        anchors.leftMargin: 4;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 4
        KeyNavigation.left: blueColor;
        KeyNavigation.tab: pinkColor;
//        onColorPicked: {
//            coloredText.color = clr;
//        }
    }
    Component.onCompleted: {
        blueColor.colorPicked.connect(setTextColor);
        pinkColor.colorPicked.connect(setTextColor);
    }
    function setTextColor(clr){
        coloredText.color = clr;
    }
}
