import QtQuick 2.7

Page1Form {
    button1.onClicked: {
        //console.log("Button Pressed. Entered text: " + textField1.text);
        console.log(lusername.text + luserpasswd.text);
        db2.CreateDB();
         console.log(db2.GetModel(lusername.text,luserpasswd.text));
    }

}
