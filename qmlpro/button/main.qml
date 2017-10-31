import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle{
        id:texttect
        anchors.centerIn: parent
        Text{
            id:mytext
            color:"red"
            text:"black"
            anchors.centerIn: parent

        }
        Rectangle{

            id:buttonrect0
            anchors.top:mytext.bottom
            anchors.topMargin: 5
            anchors.left:mytext.left
            anchors.leftMargin: -30

            Button{

                text:"push me";
                onClicked:{
                    mytext.color="blue"

                }
            }

        }
        Rectangle{

            id:buttonrect1
            anchors.top:mytext.bottom
            anchors.topMargin: 50
            anchors.left:mytext.left
            anchors.leftMargin: -30

            Button{

                text:"quit";
                onClicked:{
                    Qt.quit();

                }
            }

        }
    }

}
