import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle{
        id:sentsig
         signal sent(var str);
    }
    function slotsent(str){
        console.log(str);
    }

    MouseArea{
        anchors.fill:parent
        onClicked: {
            sentsig.sent(123);
            sentsig.sent.connect(slotsent);

        }
    }

}
