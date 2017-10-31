import QtQuick 2.8
import QtQuick.Window 2.2
import shj.qt 1.0;
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Button{
        id:mybtn
        text: "open file"
        ButtonStyle{
            background: Rectangle{
                width:75
                height:35;
                radius: 4;
            }
        }
        onClicked:
            fileDialog.visible = true;
    }
    RWFile{
        id:rwf
    }
    TextArea{
        id: mytext
        anchors.top: mybtn.bottom

    }

    FileDialog {
          id: fileDialog
          title: "Please choose a file"
          folder: shortcuts.home
          nameFilters: [ "text files (*.txt)", "All files (*)" ]
          onAccepted: {
              rwf.openfile(fileDialog.fileUrl);
              mytext.text = rwf.showContext();
          }
//          onRejected: {
//              console.log("Canceled")
//              Qt.quit()
//          }
          Component.onCompleted: visible = false
      }
}
