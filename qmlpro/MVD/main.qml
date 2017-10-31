import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 1.4;
import QtQuick.Layouts 1.3
Window {
    visible: true
    width: 480
    height: 640
    title: qsTr("Hello World")
    Component{
        id:userDelegate
        Item {
            id: wrapData
            width: parent.width;
            height:30;
            MouseArea{
                anchors.fill: parent;
                onClicked: wrapData.ListView.view.currentIndex = index;
            }
            RowLayout{

                anchors.left: parent.left;
                anchors.verticalCenter: parent.verticalCenter;
                spacing: 8;
                Text {

                    text:username;
                    color: wrapData.ListView.isCurrentItem ? "red":"blue";
                    font.pixelSize: wrapData.ListView.isCurrentItem ? 20 :18
                }
                Text {

                    text:sex;
                    color: wrapData.ListView.isCurrentItem? "red":"blue";
                    font.pixelSize: wrapData.ListView.isCurrentItem? 20 :18
                }
                Text {

                    text:age;
                    color: wrapData.ListView.isCurrentItem? "red":"blue";
                    font.pixelSize: wrapData.ListView.isCurrentItem? 20 :18
                }

            }
        }
    }
    ListView{
        id:listView;
        anchors.fill: parent;
        delegate: userDelegate;
        model: ListModel{
            id:userModel
            ListElement{
                username:"123";
                sex:"nan"
                age:"18";
            }
            ListElement{
                username:"123";
                sex:"nan"
                age:"18";
            }
            ListElement{
                username:"123";
                sex:"nan"
                age:"18";
            }
            ListElement{
                username:"123";
                sex:"nan"
                age:"18";
            }
        }

    }
    Button{
        id:mybtn
        onClicked:

            listView.model.append({"username":"mix3","sex":"nv","age":"15"});
    }


}
