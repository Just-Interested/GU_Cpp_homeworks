import QtQuick
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Rectangle")

    GridLayout {
        anchors.fill: parent
        Rectangle {
            id: _rect
            color: "red"
            Layout.alignment: Qt.AlignCenter
            Layout.preferredHeight: 150
            Layout.preferredWidth: 150

            RotationAnimator {
                id: _rotation
                target: _rect;
                from: 0;
                to: 360;
                duration: 1000
            }

            MouseArea {
                anchors.fill: parent
                acceptedButtons: Qt.LeftButton | Qt.RightButton
                onClicked: (mouse) => {
                    if (mouse.button === Qt.LeftButton){
                        _rect.color =  Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
                    }
                    if (mouse.button === Qt.RightButton){
                        _rotation.start();
                    }
                }
                onDoubleClicked: (mouse) => {
                    if (mouse.button === Qt.LeftButton){
                        _rect.radius =  _rect.width / 2;
                    }
                }
            }
        }
    }
}
