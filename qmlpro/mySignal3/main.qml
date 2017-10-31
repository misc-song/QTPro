import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    MouseArea{
        anchors.fill:parent;
        onPressed: sig.sentSig();
    }

    Rectangle{
        id:sig
        signal sentSig();
        Component.onCompleted:{
            sig.sentSig.connect(fun1);
            sig.sentSig.connect(fun2);
            sig.sentSig.connect(fun3);
        }
    }
    function fun1(){
        console.log("fun1");
    }
    function fun2(){
        console.log("fun2");
    }
    function fun3(){
        console.log("fun3");
    }

}
