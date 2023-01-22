import QtQuick 2.0
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    objectName: "customButton"
    property alias buttonText: _buttonText.text
    property alias buttonWidth: _rect.width
    property alias buttonHeight: _rect.height
    signal buttonClicked(msg : string)
    id: _rect
    width: 100
    height: 25
    color: "transparent"
    border {
        color: "purple"
        width: 2
    }
    radius: 20
    Text {
        id: _buttonText
        anchors.centerIn: parent
        color: _rect.border.color
        font.bold: true
        font.pixelSize: 14
        text: "Test"
    }
    MouseArea {
        id: _mArea
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton
        onPressed: {
            _rect.border.color = Qt.lighter("purple", 1.5)
        }
        onReleased: {
            _rect.border.color = "purple"
        }
        onClicked: {
            _rect.buttonClicked("data to transmit")
        }
    }
}
