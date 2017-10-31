import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    maximumWidth: 640;
    maximumHeight: 480;
    title: qsTr("Hello World")
    header: TabBar{
        id:tabBar
        currentIndex:swipeView.currentIndex;
        TabButton {
            text: qsTr("Login")
        }
        TabButton {
            text: qsTr("Register")
        }
    }
    SwipeView{
        id:swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex
        Login{
            id:login;
        }
        Register{
            id:register
        }
    }
}
