import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.2
import QtQuick.Dialogs 1.1
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    BusyIndicator{
        id : busy;
        running:false;
        z:3
    }
    Button{
        id:openfilebtn
        anchors.top : parent.top
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5

        text:"open file"
        style: ButtonStyle{
            background: Rectangle{
                implicitHeight: 30
                implicitWidth: 70
                radius: 4
                color: control.hovered ? "#a0a0a0" : "#404040";
            }
        }
        onClicked: openfile.open();
    }
    Text {
        id: filename
        visible: false
        anchors.top : parent.top
        anchors.topMargin: 15
        anchors.left: openfilebtn.right
        anchors.leftMargin: 15
        text:"123"
        color:"blue"

    }
    TextArea{
        id : textdetail
        anchors.top:openfilebtn.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        onTextChanged: {
            if(textdetail.length>0)
            {
                busy.running = false;
                filename.visible = true;
                filename.text = openfile.fileUrl;
            }
            else
            {
                 busy.running = true;
                 filename.visible = true;
                 filename.text = openfile.fileUrl;
            }

        }
    }
    FileDialog{
        id:openfile
        title:"open text file"
        nameFilters: ["text(*.txt)"];
        onAccepted: {
            openfile.fileUrl
            textdetail.append(openfile.fileUrl);

        }
    }






















}
