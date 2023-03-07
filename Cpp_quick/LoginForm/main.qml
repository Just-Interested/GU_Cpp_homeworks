import QtQuick
import QtQuick.Controls 2.15

Window {
    id: _mainWindow
    width: 640
    height: 480
    color: "#e5ecef"
    visible: true
    title: qsTr("Login")

    function createLoginForm(parent) {
        var component = Qt.createComponent("LoginFormWidget.qml");
        var login_form = component.createObject(parent);
        if (login_form == null) {
            console.log("Error creating object");
        }
        else {
            login_form.successfullLogin.connect(showPage);
        }
    }

    Component.onCompleted: {
        createLoginForm(_mainWindow);
    }

    function showPage(page_id = 0){
        console.log("page_id: " + page_id)
        var component = Qt.createComponent("Page" + page_id + ".qml")
        var page = component.createObject(_mainWindow);
        if (page == null) {
            console.log("Error creating object");
        }
        else {
            console.log("Success!")
            page.toNextPage.connect(showPage)
        }
    }
}
