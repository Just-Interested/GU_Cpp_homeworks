import QtQuick
import QtQuick.Controls 2.15

Rectangle {
    id: secondaryFrame
    color: "white"
    anchors.centerIn: parent // Размещение компонента внутри родительского
    radius: 5 // Закругление углов с выбранным радиусом
    width: 300
    height: 250
    property string textColor: "#535353"
    property string login: "adm"
    property string password: "adm"
    signal successfullLogin

    Column {
        anchors.fill: parent
        padding: 32
        spacing: 32
        TextField {
            id: loginTextField
            anchors.horizontalCenter: parent.horizontalCenter
            placeholderText: qsTr("Логин")
            color: secondaryFrame.textColor
            Keys.onEnterPressed: checkCredentials()
            Keys.onReturnPressed: checkCredentials()
        }
        TextField {
            id: passwordTextField
            echoMode: TextInput.Password // звездочки вместо пароля
            anchors.horizontalCenter: parent.horizontalCenter
            placeholderText: qsTr("Пароль")
            color: secondaryFrame.textColor
            Keys.onEnterPressed: checkCredentials()
            Keys.onReturnPressed: checkCredentials()
        }
        Button {
            id: submitButton
            width: 200
            height: 40
            background: Rectangle {
                color: parent.down ? "#bbbbbb" :
                (parent.hovered ? "#d6d6d6" : "#f6f6f6")
            }
            text: qsTr("Вход")
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: checkCredentials()
        }
    }

    ParallelAnimation{
        id: failAnimation
        SequentialAnimation {
            PropertyAnimation {
                targets: [loginTextField, passwordTextField]
                property: "color"
                to: "dark red"
                duration: 0
            }
            PropertyAnimation {
                targets: [loginTextField, passwordTextField]
                property: "color"
                to: secondaryFrame.textColor
                duration: 400
            }
        }
        SequentialAnimation {
            NumberAnimation { target: secondaryFrame; property: "anchors.horizontalCenterOffset"; to: -5; duration: 50 }
            NumberAnimation { target: secondaryFrame; property: "anchors.horizontalCenterOffset"; to: 5; duration: 100 }
            NumberAnimation { target: secondaryFrame; property: "anchors.horizontalCenterOffset"; to: 0; duration: 50 }
        }
    }

    function checkCredentials() {
        if (login === loginTextField.text && password === passwordTextField.text){
            console.log("Удачный вход");
            secondaryFrame.successfullLogin()
            secondaryFrame.destroy(100);
        }
        else {
            failAnimation.start()
        }
    }
}

