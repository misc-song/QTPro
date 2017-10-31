import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.2
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Component{//D
        id:cityDelegate
        Item{
            id:wraper
            width: parent.width;
            height: 30;
            MouseArea
            {
                anchors.fill: parent//鼠标填充parent的大小
                onClicked: wraper.ListView.view.currentIndex = index;//ListView 暴露了一个index属性 代表当前delegate对应Item索引的位置
                onDoubleClicked: wraper.ListView.view.model.remove(index);
            }
            RowLayout{
                anchors.left: parent.left;
                anchors.verticalCenter: parent.verticalCenter;
                spacing: 8;
                Text {
                    text: cname;
                    color:  wraper.ListView.isCurrentItem ? "red" : "blue";
                    //ListView定义了delayRemove,isCurrentItem,nextSecetion,previousSection,section,view等附加属性
                    //以及add,remove两个附加信号可以在delegate中直接使用这些附加属性和信号
                    //非顶层Item则需要同过顶层的id老访问这些附加属性
                    font.pixelSize: wraper.ListView.isCurrentItem ? 22 : 18;
                    Layout.preferredWidth: 120;
                }
                Text {
                    text: csize;
                    color:  wraper.ListView.isCurrentItem ? "red" : "blue";
                    font.pixelSize: wraper.ListView.isCurrentItem ? 22 : 18;
                    Layout.preferredWidth: 80;
                }
                Text {
                    text: cmoney;
                    color:  wraper.ListView.isCurrentItem ? "red" : "blue";
                    font.pixelSize: wraper.ListView.isCurrentItem ? 22 : 18;
                    Layout.fillHeight: true;
                }
            }
        }
    }

    Component{
        id:cheader;
        Item {
            width: parent.width;
            height: 30;
            RowLayout{
                anchors.left: parent.left;
                anchors.verticalCenter: parent.verticalCenter;
                spacing: 8;
                Text {
                    text: "Cname";

                    Layout.preferredWidth: 120;
                }
                Text {
                    text: "Csize";

                    Layout.preferredWidth: 80;
                }
                Text {
                    text: "Cmoney";

                    Layout.fillHeight: true;
                }
            }

        }

    }
    Component{
        id:foot
        Item {
            id: footerRootItem;
            width: parent.width;
            height: 30;
            property alias text: txt.text;
            signal clean();
            signal add();
            signal moveDown();
            Text {
                anchors.left: parent.left;
                anchors.top: parent.top;
                anchors.bottom: parent.bottom;
                id:txt;
                width: parent.width;
                font.italic: true;
                color: "blue";
                height: 30;
                verticalAlignment: Text.AlignVCenter;
            }
            Button{
                id:cleanAll
                anchors.right: parent.right;
                anchors.verticalCenter: parent.verticalCenter;
                text: "Clear";

                onClicked: footerRootItem.clean();
            }
            Button{
                id:addon
                anchors.right: cleanAll.left;
                anchors.verticalCenter: parent.verticalCenter;
                text: "Add";

                onClicked: footerRootItem.add();
            }
            Button{
                anchors.right: addon.left;
                anchors.verticalCenter: parent.verticalCenter;
                text: "Dowm";

                onClicked: footerRootItem.moveDown();
            }
        }
    }

    Component{
        id:cityModel
        ListModel{


            ListElement{
                cname:"beijing";
                csize:"da"
                cmoney:"youqian"
            }
            ListElement{
                cname:"anhui";
                csize:"da"
                cmoney:"meiqina"
            }
            ListElement{
                cname:"wuhu";
                csize:"da"
                cmoney:"youqian"
            }

        }
    }
    ListView{
        id:listView
        anchors.fill:parent;
        delegate: cityDelegate;
        model:cityModel.createObject(listView);
        header: cheader;
        footer:foot;
        focus: true;
        highlight: Rectangle
        {
            color:"lightblue"
        }
        onCurrentIndexChanged: {
            if(listView.currentIndex >= 0)
            {
                var data = listView.model.get(listView.currentIndex);//获取当前索引中对应的值
                listView.footerItem.text = data.cname + ", " + data.csize + ", " + data.cmoney; //将索引所对应的值取出来
            }
            else
            {
                listView.footerItem.text = " ";//如果索引值小于0啥也 不显示
            }
        }
        add:Transition {
            ParallelAnimation
            {
                NumberAnimation{
                    property: "opacity";//动画目标
                    from:0;//起始参数
                    to:1.0;//结束参数
                    duration: 400;//持续时间(单位毫秒)
                }
                NumberAnimation
                {
                    property: "y";
                    from:0;
                    duration: 400;
                }
            }

        }
        remove:Transition {
            ParallelAnimation
            {
                NumberAnimation{
                    property: "opacity";//动画目标
                    to:1.0;//结束参数
                    duration: 400;//持续时间(单位毫秒)
                }
                NumberAnimation
                {
                    property: "y";
                    to:0;
                    duration: 400;
                }
            }

        }
        displaced: Transition{
            SpringAnimation{//弹簧动画
                properties: "y";
                spring: 3;
                damping: 0.1;
                epsilon: 0.25;
            }
        }
        move: Transition{
            NumberAnimation{//数字 动画
                property: "y";
                duration: 400;
                easing.type: Easing.InQuart;
            }
        }

        function addOne()
        {
            model.append({"cname":"ww","csize":"da","cmoney":"yuqian"});
        }
        function moveDown()
        {
            if(currentIndex +1 <model.count)
            {
                model.move(currentIndex,currentIndex+1,1);
            }
        }

        Component.onCompleted: {
            listView.footerItem.clean.connect(listView.model.clear);
            listView.footerItem.add.connect(listView.addOne);
            listView.footerItem.moveDown.connect(listView.moveDown);
        }

    }
}

