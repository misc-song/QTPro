import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle{
        id:myrect
        focus: true
        Keys.onEnterPressed: Qt.quit();
        Keys.onEscapePressed: Qt.quit()
        Keys.onPressed:{
            switch(event.key){
            case Qt.Key_0:
            case Qt.Key_1:
            case Qt.Key_2:
            case Qt.Key_3:
            case Qt.Key_4:
            case Qt.Key_5:
            case Qt.Key_6:
            case Qt.Key_7:
            case Qt.Key_8:
            case Qt.Key_9:
                event.accpepted = true;
                keyView.text = event.key - Qt.Key_0;
            }


        }
    }
    Text {
        id: keyView
        font.bold: true
        font.pixelSize: 24
        text: qsTr("text")
        anchors.centerIn: parent;
    }
}
