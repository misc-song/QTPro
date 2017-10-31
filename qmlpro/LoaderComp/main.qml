import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Component{
        id:mycom
        Rectangle{
            width:25;
            height:25;
            border.color: "black"
            border.width: 1
        }
    }
//    Loader{
//        sourceComponent: mycom;//Loader的sourceComponent:属性加载的是对象Component的id
//    }
//    Loader{
//        source: "myComp.qml"//Loader的source: 属性加载的是qml文件
//    }
    //当source的值变为undefined的时候对象会被自动销毁
}
