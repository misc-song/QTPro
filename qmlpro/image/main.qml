import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle
    {
        width:640
        height:480
        color:"#121212"
        BusyIndicator{
            id:busy
            running: true
            anchors.centerIn: parent
            z:2
        }
        Text {
            id: statelable
            visible: false
            anchors.centerIn: parent
            z:3
        }

        Image {
            id: myimg
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit;
            onStatusChanged: {
                if(myimg.status===Image.Loading)
                {
                    busy.running = true;
                    statelable.visible = false;
                }else if(myimg.status === Image.Ready)
                {
                    busy.running = false;
                }
                else if(myimg.states === Image.Error)
                {
                    busy.running = false;
                    statelable.visible = true;
                    statelable.text = "Error";
                }
            }
            Component.onCompleted: {
                myimg.source="http://i2.sinaimg.cn/gm/j/i/2014-09-01/U4341P115T41D244151F757DT20140901170116.jpg"
            }
        }
    }
}
