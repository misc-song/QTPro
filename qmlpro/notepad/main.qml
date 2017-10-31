import QtQuick 2.8


import Qt.labs.platform 1.0
import QtQuick.Controls 1.4
import shj.qt 1.0;
ApplicationWindow {
    id: window
    width: 640;
    height:480;
    title: "shj's notepad"
    visible: true
    menuBar: MenuBar {
        Menu {
            title: "File"
            MenuItem {
                text: "New File";
                shortcut: "Ctrl+N"
                onTriggered: {

                }
            }
            MenuItem {
                text: "Open File";
                shortcut: "Ctrl+O"
                onTriggered: {
                    openFileDialog.open();
                }
            }
            MenuItem {
                text: "Save File";
                shortcut: "Ctrl+S"
                onTriggered: {
                    saveFileDialog.open();
                }
            }
            MenuItem {
                text: "Save As...";
                onTriggered: {

                }
            }
            MenuSeparator{}
            MenuItem {
                text: "Page Setting";
                onTriggered: {

                }
            }

            MenuItem {
                text: "Print";
                onTriggered: {

                }
            }
            MenuSeparator{}
            MenuItem {
                text: "Exit";
                onTriggered: {
                    Qt.quit();
                }
            }
        }
        Menu {
            title:"Edit"
            MenuItem {
                text: "Undo"
                shortcut: "Ctrl+Z"
            }
            MenuSeparator{}
            MenuItem {
                text:"Cut"
                shortcut: "Ctrl+X"
            }
            MenuItem {
                text:"Copy"
                shortcut: "Ctrl+C"
            }
            MenuItem {
                text:"Delete"
                shortcut: "Del"
            }
            MenuItem {
                text:"Paste"
                shortcut: "Ctrl+V"
            }
            MenuSeparator{}
            MenuItem {
                text:"Find"
                shortcut: "Ctrl+F"
            }
            MenuItem {
                text:"Find Next"
                //shortcut: "F3"
            }
            MenuItem {
                text:"Replace"
                shortcut: "Ctrl+H"
            }
            MenuItem {
                text:"Go To"
                shortcut: "Ctrl+G"
            }
            MenuSeparator{}
            MenuItem {
                text:"Select All"
                shortcut: "Ctrl+A"
            }
            MenuItem {
                text:"Time/Date"
                //shortcut: "F5"
            }
        }
        Menu{
            title:"Formate"
            MenuItem{
                text: "Auto  Linefeed"
            }
            MenuItem{
                text: "Text Family"
            }
        }
        Menu{
            title:"View"
            MenuItem{
                text: "Status Bar "
            }

        }
        Menu{
            title:"Help"
            MenuItem{
                text: "Show Help"
            }
            MenuItem{
                text: "About NotePad"
            }
        }
    }

    Rectangle{
        anchors.fill: parent;
        TextEdit{
            anchors.fill: parent;
            id:myedit
            wrapMode: TextEdit.Wrap;
            onTextChanged:{

            }
        }
    }
    FileDialog {
        id: saveFileDialog
        title: "Please Select A File"
        visible: false;
        fileMode:FileDialog.SaveFile;
        //folder: "C:/Users/song/Desktop/";
        nameFilters: [ "Text files (*.txt)", "All files (*)" ]
        onAccepted: {
            saveFile.savefile(saveFileDialog.file,myedit.text)
            //myedit.text = readFile.showContext();
        }

        onRejected: {
            console.log("Canceled")
            //Qt.quit()
        }

    }
    FileIO{
        id:readFile

    }
    FileIO{
        id:saveFile

    }
    FileDialog{
        id:openFileDialog
        title: "Please Select A File"
        visible: false;
        //folder: "C:/Users/song/Desktop/";
        nameFilters: [ "Text files (*.txt)", "All files (*)" ]
        onAccepted: {
            readFile.openfile(openFileDialog.file);
            myedit.text = readFile.showContext();
        }
        onRejected: {
            console.log("Canceled")
            //Qt.quit()
        }
    }
    //    statusBar: {

    //    }


}
