import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.2
import FileIO 1.0
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    FileDialog{
        id:openDialog
        title:"open file"
        onAccepted:{

             myFile.setSource(openDialog.fileUrl)
            document.text =myFile.read();

        }
    }
    Button {
        id: fileButton
        text: "File"
        onClicked: menu.open()

        Menu {
            id: menu
            y: fileButton.height

            MenuItem {
                text: "New..."
                onTriggered: document.reset()
            }
            MenuItem {
                text: "Open..."
                onTriggered: openDialog.open()

            }
            MenuItem {
                text: "Save"
                onTriggered: saveDialog.open()
            }
            MenuSeparator{
                padding: 0
                topPadding: 12
                bottomPadding: 12
                contentItem: Rectangle {
                    implicitWidth: 200
                    implicitHeight: 1
                    color: "#1E000000"
                }
            }
            MenuItem {
                text: "Exit"
                onTriggered: Qt.quit()
            }
        }
    }
    Button {
        id: editButton
        text: "Edit"
        x:fileButton.width
        onClicked: menu2.open()

        Menu {
            id: menu2
            y: editButton.height

            MenuItem {
                text: "undo"
                onTriggered: document.reset()
            }
            MenuSeparator{
                padding: 0
                topPadding: 12
                bottomPadding: 12
                contentItem: Rectangle {
                    implicitWidth: 200
                    implicitHeight: 1
                    color: "#1E000000"
                }
            }
            MenuItem {
                text: "cut"
                onTriggered: document.cut()

            }
            MenuItem {
                text: "copy"
                onTriggered: document.copy()
            }

            MenuItem {
                text: "paste"
                onTriggered: document.paste()
            }
        }
    }
    TextEdit{
        id:document
        width: 600
        height: 450
        y:fileButton.height
        selectByMouse: true
    }
    FileIO {
        id: myFile
        source: openDialog.fileUrl
        onError: console.log(msg)

    }
}
