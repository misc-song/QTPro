import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Keys.enabled: true
    Text {
        id: moveT
        text: qsTr("hello qt")
        focus: true
        Keys.onPressed: {
            switch(event.key){
            case Qt.Key_Left:
                moveT.x -=10;
                break;
            case Qt.Key_Right:
                moveT.x +=10;
                break;
            case Qt.Key_Down:
                moveT.y -=10;
                break;
            case Qt.Key_Up:
                moveT.y+=10;
                break;
            default:
                return ;
            }
            event.accpted =true;

        }
        //Keys.forwardTo: [moveT];
    }

}
