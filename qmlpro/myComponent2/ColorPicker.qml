import QtQuick 2.0

Rectangle{
    id:colorPicker
    width: 50;
    height: 30;
    signal colorPicked(color clr);
    function configureBorder(){
        colorPicker.border.width = colorPicker.focus ? 2 : 0;
        colorPicker.border.color = colorPicker.focus ? "#90D750" : "#8080808";
    }
    MouseArea{
        anchors.fill:parent;
        onClicked: {
            colorPicker.colorPicked(colorPicker.color);
            mouse.accpted = true;
            colorPicker.focus = true;
        }
    }
    Keys.onReturnPressed: {
        colorPicker.colorPicked(colorPicker.color);
        event.accpted = true;
    }
    Keys.onSpacePressed: {
        colorPicker.colorPicked(colorPicker.color);
        event.accpted = true;
    }
    onFocusChanged: {
        configureBorder();
    }
    Component.onCompleted: {
        configureBorder();
    }
}
