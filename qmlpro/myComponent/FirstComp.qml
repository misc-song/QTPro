import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.1
Button{
    style: ButtonStyle{
        background: Rectangle{
            implicitHeight: 30;
            implicitWidth: 70;
            color: control.hovered ? "#404040" : "#233333";
            radius: 4
        }
    }
}
