import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import shj.qt 1.0
ApplicationWindow {
    visible: true
    width: 640
    height: 480
    maximumWidth: 640;
    maximumHeight: 480;
    id:useraccess;
    title: qsTr("User Access")
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
        Item {
            width: 640
            height: 480
            Image {
                width: 640;
                height: 480;
                fillMode:Image.PreserveAspectFit

                id: logpic
                source: "./lpic.jpg"
            }
            RowLayout {
                id: row1
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 120
                anchors.top: parent.top
                Label {
                    id: userNameLabel
                    text: "账   号:"
                    font.pixelSize: 25
                }
                TextField {
                    id: lusername
                    echoMode: TextField.Normal
                    font.pixelSize: 25
                    Layout.minimumWidth: 200
                    onPressed:{
                        errorinfologin.visible = false;
                    }
                }
            }
            RowLayout {
                id: row2
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 60
                anchors.top: row1.top
                Label {
                    id: luserPasswdLabel
                    text: "密   码:"
                    font.pixelSize: 25
                }
                TextField {
                    id: luserpasswd
                    echoMode: TextField.Password
                    font.pixelSize: 25
                    Layout.minimumWidth: 200
                    onPressed:{
                        errorinfologin.visible = false;
                    }
                }
            }
            RowLayout {
                id: row3
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 70
                anchors.top: row2.top
                Button {
                    id: button1
                    text: qsTr("登    录")
                    Layout.minimumWidth: 200
                    onClicked: {
                        if(login.CreateDB())
                        {
                            if(!login.GetModelByName(lusername.text))
                            {
                                errorinfologin.visible = true;
                                errorinfologin.text = "用户不存在";
                            }

                            if(login.GetModel(lusername.text,luserpasswd.text))
                            {
                                tabBar.visible = false;
                                swipeView.visible = false;
                                mainpage.visible = true;
                            }

                            else{
                                errorinfologin.visible = true;
                                errorinfologin.text = "用户名或密码不正确";
                            }
                        }
                    }
                }
            }
            RowLayout {
                id: row4
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 60
                anchors.top: row3.top
                Label {
                    id:errorinfologin
                    visible: false;
                }


            }
            DBAccess{
                id:login
            }

        }
        Item {
            width: 640;
            height:480;
            Image {
                width: 640;
                height: 480;
                fillMode:Image.PreserveAspectFit
                id: regpic
                source: "./rpic.jpg"
            }
            RowLayout {
                id: rrow1
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 120
                anchors.top: parent.top
                Label {
                    id: ruserNameLabel
                    text: "账    号:"
                    font.pixelSize: 25
                }
                TextField {
                    id: rusername
                    echoMode: TextField.Normal
                    font.pixelSize: 25
                    Layout.minimumWidth: 200
                }
            }
            RowLayout {
                id: rrow2
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 60
                anchors.top: rrow1.top
                Label {
                    id: ruserPasswdLabel
                    text: "密    码:"
                    font.pixelSize: 25
                }

                TextField {
                    id: ruserpasswd
                    echoMode: TextField.Password
                    font.pixelSize: 25
                    Layout.minimumWidth: 200
                    onPressed: {
                        errorinforegister.visible = false;
                    }
                }
            }
            RowLayout {
                id: rrow3
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 60
                anchors.top: rrow2.top
                Label {
                    id: ruserPasswdRepeatLabel
                    text: "确认密码:"
                    font.pixelSize: 25
                }

                TextField {
                    id: ruserpasswdrepeat
                    echoMode: TextField.Password
                    font.pixelSize: 25
                    Layout.minimumWidth: 200
                    onPressed: {
                        errorinforegister.visible = false;
                    }
                }
            }
            RowLayout {
                id: rrow4
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 70
                anchors.top: rrow3.top
                Button {
                    id: button2
                    text: qsTr("注    册")
                    Layout.minimumWidth: 200
                    onClicked:
                    {
                        if(ruserpasswd.text == ruserpasswdrepeat.text)
                        {
                            if(register.CreateDB())
                            {
                                if(register.InsertModel(rusername.text,ruserpasswdrepeat.text))
                                {
                                    errorinforegister.visible = true;
                                    errorinforegister.text="注册成功 请登录";
                                }
                                else
                                {
                                    errorinforegister.visible = true;
                                    errorinforegister.text="注册失败 请联系管理员";
                                }
                            }
                            else
                            {

                            }
                        }
                        else
                        {
                            errorinforegister.visible = true;
                            errorinforegister.text="两次密码不同";
                        }


                    }
                }
            }
            RowLayout {
                id: rrow5
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 60
                anchors.top: rrow3.top
                Label {
                    id:errorinforegister
                    visible: false;
                }


            }
            DBAccess{
                id:register;
            }

        }

    }
    MainPage{
        id:mainpage
        visible: false;
    }
}
