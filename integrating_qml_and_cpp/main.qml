import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import FileIO 1.0
Window {
    visible: true
    width: 610
    height: 500
    title: qsTr("Hello World")
    Rectangle{
        id:editRec
        width:610
        height:460
        border.color: "black"
        border.width: 1

        TextEdit{
            id:editArea
            width: 600;
            height: 450;
            textMargin: 10

        }
    }
    Button{
        id:saveBtn
        text:"save"
        y:editRec.height;
        onClicked: {
            FileIO.write(editArea.text)
        }
    }
}
