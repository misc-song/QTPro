import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import Qt.labs.platform 1.0
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Button{
        id:openfile
        text:"open";
        onClicked: openfiledialog.open()
    }
    FileDialog{
        id:openfiledialog
        selectedNameFilter.index: 1
        nameFilters: ["Text files (*.txt)", "HTML files (*.html *.htm)"]

    }
    Rectangle{
        border.color: "black";
        border.width: 2
        y:openfile.height
        width:parent.width;
        height:parent.height-openfile.height;

        TextEdit {
            id: textEdit
            width:parent.width
            height:parent.height
            leftPadding: 5
            topPadding: 5
            text: qsTr("Enter some text...")
            //        verticalAlignment: Text.AlignVCenter
            //        anchors.top: parent.top
            //        anchors.horizontalCenter: parent.horizontalCenter
            //        anchors.topMargin: 20
            //        Rectangle {
            //            anchors.fill: parent
            //            anchors.margins: -10
            //            color: "transparent"
            //            border.width: 1
            //        }
        }
    }
}
