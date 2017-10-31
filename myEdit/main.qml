import QtQuick 2.8
import QtQuick.Window 2.2

Window {
        visible: true//窗口可见性
        width: 640
        height: 480
        title: qsTr("Hello World")//标题

    //    Rectangle {
    //        width: 320;
    //        height: 480;
    //        color: "blue";
    //        border.color: "#808080";
    //        border.width: 2;
    //        radius: 12;
    //    }
    //    Rectangle {
    //        width: 100;
    //        height: 100;
    //        gradient: Gradient {
    //            GradientStop { position: 0.0; color: "#202020"; }
    //            GradientStop { position: 0.33; color: "blue"; }
    //            GradientStop { position: 1.0; color: "#FFFFFF"; }
    //        }
    //    }
    //    Rectangle {
    //        width: 100;
    //        height: 100;
    //        anchors.leftMargin: 100;
    //        rotation: 45;
    //        gradient: Gradient {
    //            GradientStop { position: 0.0; color: "#202020"; }
    //            GradientStop { position: 1.0; color: "#A0A0A0"; }
    //        }
    //    }

    //    Rectangle {
    //        x: 20;
    //        y: 20;
    //        width: 150;
    //        height: 100;
    //        color: "#606080";
    //        z: 0.1;
    //    }

    //    Rectangle {
    //        width: 100;
    //        height: 100;
    //        anchors.centerIn: parent;
    //        color: "#a0c080";
    //        z: 1;
    //        opacity: 0.6;
    //    }
    Rectangle {
        width: 300;
        height: 200;
        color: "#c0c0c0";
        focus: true;
        Keys.enabled: true;
        Keys.onEscapePressed: Qt.quit();
        Keys.onBackPressed: Qt.quit();
        Keys.onPressed: {
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
                keyView.text = event.key ;
                break;
            }
        }

        Text {
            id: keyView;
            font.bold: true;
            font.pixelSize: 24;
            text: qsTr("text");
            anchors.centerIn: parent;
        }
    }
}
