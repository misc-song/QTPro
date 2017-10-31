import QtQuick 2.2
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

//    Canvas{
//        id:mycanvans;
//        width: parent.width;
//        height: parent.height;
//        visible: false;
//        //contextType: "2d"
//        onPaint: {
//            var context = getContext("2d");
//            ctx.lineWidth = 2;
//            ctx.strokeStyle = "red";
//            ctx.fillStyle = "blue";
//            ctx.beginPath();
//            ctx.rect(100,80,120,80);
//            ctx.fill();
//            ctx.stroke();
//            //            context.lineWidth = 2;
//            //            context.strokeStyle = "red";
//            //            context.fillStyle = "blue";
//            //            context.beginPath();
//            //            context.rect(100,80,120.80);
//            //            context.fill();
//            //            context.stroke();
//        }

//    }

//    Canvas{

//        width:parent.width;
//        height:parent.height;
//        visible:false;
//        onPaint: {
//            var ctx = getContext("2d");
//            ctx.lineWidth = 2;//画笔的粗细
//            ctx.strokeStyle = "red";//画笔的颜色
//            ctx.fillStyle = "blue";//填充色
//            ctx.beginPath();//准备绘制
//            ctx.rect(100,80,120,80);//所化的形状
//            ctx.fill();//填充
//            ctx.stroke();//绘制
//        }
//    }
    Canvas{
        width:parent.width;
        height: parent.height;
        onPaint: {
            var ctx = getContext("2d");
            ctx.lineWidth = 2;
            ctx.strokeStyle = "red";
            var gradient = ctx.createLinearGradient(60,50,180,130);
            gradient.addColorStop(1,0,0,1.0);
            gradient.addColorStop(0,0,1,1.0);
            ctx.fillStyle = gradient;
            ctx.beginPath();
            ctx.rect(60,50,120,80);
            ctx.fill();
            ctx.stroke();
            gradient = ctx.createRadialGradient(230,160,20,260,200,50);
            gradient.addColorStop(0.0,Qt.rgba(1,0,0,1.0));
            gradient.addColorStop(1.0,Qt.rgba(0,0,1,1.0));
            ctx.fillStyle = gradient;
            ctx.beginPath();
            ctx.rect(200,140,80,80);
            ctx.fill();
            ctx.stroke();
        }
    }


}
