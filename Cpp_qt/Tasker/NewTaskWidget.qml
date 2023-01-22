import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Frame {
    id: _newTaskWidget
    objectName: "newTaskWidget"
    width: parent.width
    signal addNewTask(string taskname, int progressVal, string deadline)
    background: Rectangle {
        color: "transparent"
    }
    RowLayout {
        anchors.fill: parent
        Rectangle {
            color: "transparent"
            Layout.fillWidth: parent
            Layout.preferredHeight: 25
            TextField {
                id: _taskname
                selectByMouse: true
                width: parent.width
                anchors.verticalCenter: parent.verticalCenter
                placeholderText: "Enter task description"
            }
        }
        Rectangle {
            color: "transparent"
            Layout.preferredWidth: parent.width / 5
            Layout.preferredHeight: 25
            TextField {
                id: _deadline
                selectByMouse: true
                width: parent.width
                anchors.verticalCenter: parent.verticalCenter
                placeholderText: "dd.mm.yyyy"
                validator: RegularExpressionValidator { regularExpression: /[0-3][0-9]\.[0-1][0-9]\.[0-9]{4}/ }
            }
        }
        Rectangle {
            color: "transparent"
            Layout.preferredWidth: 50
            Layout.preferredHeight: 25
            SpinBox {
                id: _progressVal
                width: parent.width
                anchors.centerIn: parent
                from: 0
                to: 10
                value: 5
            }
        }
        Rectangle {
            color: "transparent"
            Layout.preferredWidth: parent.width / 5
            Layout.preferredHeight: 25
            CustomButton {
                id: _customButton
                buttonHeight: parent.height
                buttonWidth: parent.width
                buttonText: "Add task"
            }
            Connections {
                target: _customButton
                function onButtonClicked(msg){
                    _newTaskWidget.addNewTask(_taskname.text, _progressVal.value, _deadline.text)
                }
            }
        }
    }
}
