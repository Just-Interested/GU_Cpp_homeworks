import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Frame {
    id: _task_list
    width: parent.width
    background: Rectangle {
        color: "transparent"
    }
    ListView {
        id: _task_list_view
        anchors.fill: parent
        implicitWidth: 250
        implicitHeight: 250
        clip: true

        headerPositioning: ListView.OverlayHeader
        header: RowLayout {
            width: parent.width
            spacing: 5

            Rectangle {
                Layout.fillWidth: true
                Layout.minimumWidth: 100
                Layout.minimumHeight: 25
                Text {
                    anchors.centerIn: parent
                    text: "Task name"
                }
            }

            Rectangle {
                Layout.minimumWidth: 100
                Layout.preferredWidth: parent.width / 4
                Layout.minimumHeight: 25
                Text {
                    anchors.centerIn: parent
                    text: "Progress"
                }
            }

            Rectangle {
                Layout.minimumWidth: 70
                Layout.preferredWidth: parent.width / 4
                Layout.maximumWidth: 80
                Layout.minimumHeight: 25
                Text {
                    anchors.centerIn: parent
                    text: "Deadline"
                }
            }
            z: 2
        }

        model: ListModel {
            id: _listModel
            objectName: "listObject"
//            ListElement {
//                taskName: "Task 1"
//                progressVal: 5
//                deadLine: "12.12.2022"
//            }
        }

        delegate: RowLayout {
            width: parent.width
            id: _list_layout
            spacing: 5

            Rectangle {
                Layout.fillWidth: true
                Layout.minimumWidth: 100
                Layout.minimumHeight: 25
                Layout.preferredHeight: 25
                TextField {
                    selectByMouse: true
                    width: parent.width
                    anchors.verticalCenter: parent.verticalCenter
                    text: taskName
                }
            }

            Rectangle {
                Layout.minimumWidth: 100
                Layout.preferredWidth: parent.width / 4
                Layout.minimumHeight: 25
                Layout.preferredHeight: 25
                RowLayout {
                    anchors.fill: parent

                    ProgressBar {
                        Layout.fillWidth: parent
                        from: 0.0
                        to: 10.0
                        value: _progress_spinbox.value
                    }

                    SpinBox {
                        id: _progress_spinbox
                        Layout.preferredWidth: 50
                        from: 0
                        to: 10
                        stepSize: 1
                        value: progressVal
                    }
                }
            }

            Rectangle {
                Layout.minimumWidth: 70
                Layout.preferredWidth: parent.width / 4
                Layout.maximumWidth: 80
                Layout.minimumHeight: 25
                Layout.preferredHeight: 25
                TextField {
                    selectByMouse: true
                    width: parent.width
                    anchors.verticalCenter: parent.verticalCenter
                    text: deadLine
                    validator: RegularExpressionValidator { regularExpression: /[0-3][0-9]\.[0-1][0-9]\.[0-9]{4}/ }
                }
            }
        }
    }
    function addTask(task, progress, deadline) {
        _listModel.append({"taskName": task, "progressVal": progress, "deadLine": deadline});
    }
}
