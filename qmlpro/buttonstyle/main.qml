import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button {
        text: "A button"
        style: ButtonStyle {
                  background: Rectangle {
                      implicitWidth: 100
                      implicitHeight: 25
                      border.width: control.activeFocus ? 2 : 1
                      border.color: "#888"
                      radius: 4
                      gradient: Gradient {
                          GradientStop { position: 0 ; color: control.pressed ? "#ccc" : "#eee" }
                          GradientStop { position: 1 ; color: control.pressed ? "#aaa" : "#ccc" }
                      }
                  }
              }


    }




}
