import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Dialogs 1.1

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    BusyIndicator{
        id: busy
        running:false
        anchors.centerIn: parent
        z:2
    }
    Text {
        id: stateLabel
        visible:false
        anchors.centerIn: parent
        z:3
    }
    Image {
        id: imageViewer
        anchors.fill: parent
        cache:false
        fillMode: Image.PreserveAspectFit
        onStatusChanged: {
            if(imageViewer.status === Image.Loading)
            {
                busy.running = true;
                stateLabel.visible = false;
            }
            else if(imageViewer.states === Image.Ready)
            {
                busy.running = false;
            }
            else if(imageViewer.states === Image.Error)
            {
                busy.running = false;
                stateLabel.visible = true;
                stateLabel.text = "error";
            }
        }

    }
    Button{
        id:openfile
        text:"open file"
        anchors.left:parent.left
        anchors.leftMargin: 8
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        style: ButtonStyle{
            background: Rectangle{
                implicitHeight: 30;
                implicitWidth: 70;
                color: control.hovered ? "#c0c0c0" : "#a0a0a0";
                border.width: control.pressed ? 2: 1;
                radius: 4
                border.color: (control.hovered || control.pressed)? "green":"#888888";

            }
        }
        onClicked: filedialog.open();
        z:4
    }
    Text {
        id: imageimagepath
        anchors.left: openfile.right
        anchors.verticalCenter: openfile.verticalCenter;
        font.pixelSize: 8

    }
    FileDialog{
        id : filedialog
        title:"please choose image";
        nameFilters: ["image files(*.jpeg, *.png *.gif *.jpg)"]
        onAccepted: {
            imageViewer.source = filedialog.fileUrl
            var imagefile = new String(filedialog.fileUrl);
            imageimagepath.text = imagefile.slice(8);
        }
    }

}
