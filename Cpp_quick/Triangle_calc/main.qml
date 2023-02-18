import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Triangle calculator")

    GridLayout {
        Layout.fillWidth: parent
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        rows: 10
        columns: 2
        Rectangle {
            color: "transparent"
            Layout.fillWidth: parent
            Layout.preferredHeight: 30
            Layout.preferredWidth: 250
            Layout.row: 0
            Layout.column: 0
            Text {
                anchors.centerIn: parent
                text: "Введите три стороны треугольника:"
            }
        }
        Rectangle {
            color: "transparent"
            Layout.preferredHeight: 30
            Layout.preferredWidth: 250
            Layout.row: 0
            Layout.column: 1
            TextField {
                id: sideA
                width: parent.width
                height: 20
                anchors.centerIn: parent
                placeholderText: "a"
            }
        }
        Rectangle {
            color: "transparent"
            Layout.preferredHeight: 30
            Layout.preferredWidth: 250
            Layout.row: 1
            Layout.column: 1
            TextField {
                id: sideB
                width: parent.width
                height: 20
                anchors.centerIn: parent
                placeholderText: "b"
            }
        }
        Rectangle {
            color: "transparent"
            Layout.preferredHeight: 30
            Layout.preferredWidth: 250
            Layout.row: 2
            Layout.column: 1
            TextField {
                id: sideC
                width: parent.width
                height: 20
                anchors.centerIn: parent
                placeholderText: "c"
            }
        }
        Rectangle {
            color: "transparent"
            Layout.preferredHeight: 30
            Layout.preferredWidth: 250
            Layout.row: 3
            Layout.column: 1
            Button {
                anchors.verticalCenter: parent.verticalCenter
                text: "Вычислить"
                onClicked: {
                    var a = parseFloat(sideA.text);
                    var b = parseFloat(sideB.text);
                    var c = parseFloat(sideC.text);

                    var p = (a + b + c) / 2.0;
                    var s = Math.sqrt(p * (p - a) * (p - b) * (p - c));
                    result_a.text = s
                }
            }
        }
        Rectangle {
            color: "cyan"
            Layout.preferredHeight: 30
            Layout.preferredWidth: 250
            Layout.row: 4
            Layout.column: 0
            Text {
                anchors.centerIn: parent
                text: "Результат:"
            }
        }
        Rectangle {
            color: "cyan"
            Layout.preferredHeight: 30
            Layout.preferredWidth: 250
            Layout.row: 4
            Layout.column: 1
            Text {
                id: result_a
                anchors.centerIn: parent
                text: ""
            }
        }
        Rectangle {
            color: "transparent"
            Layout.preferredHeight: 30
            Layout.preferredWidth: 250
            Layout.row: 5
            Layout.column: 0
            Text {
                anchors.centerIn: parent
                text: "Введите координаты вершин:"
            }
        }
        Rectangle {
            color: "transparent"
            Layout.preferredHeight: 30
            Layout.preferredWidth: 250
            Layout.row: 5
            Layout.column: 1
            RowLayout {
                anchors.fill: parent
                TextField {
                    id: pointAx
                    width:50
                    height: 20
                    placeholderText: "x"
                }
                TextField {
                    id: pointAy
                    width:50
                    height: 20
                    placeholderText: "y"
                }
            }
        }
        Rectangle {
            color: "transparent"
            Layout.preferredHeight: 30
            Layout.preferredWidth: 250
            Layout.row: 6
            Layout.column: 1
            RowLayout {
                anchors.fill: parent
                TextField {
                    id: pointBx
                    width:50
                    height: 20
                    placeholderText: "x"
                }
                TextField {
                    id: pointBy
                    width:50
                    height: 20
                    placeholderText: "y"
                }
            }
        }
        Rectangle {
            color: "transparent"
            Layout.preferredHeight: 30
            Layout.preferredWidth: 250
            Layout.row: 7
            Layout.column: 1
            RowLayout {
                anchors.fill: parent
                TextField {
                    id: pointCx
                    width:50
                    height: 20
                    placeholderText: "x"
                }
                TextField {
                    id: pointCy
                    width:50
                    height: 20
                    placeholderText: "y"
                }
            }
        }
        Rectangle {
            color: "transparent"
            Layout.preferredHeight: 30
            Layout.preferredWidth: 250
            Layout.row: 8
            Layout.column: 1
            Button {
                anchors.verticalCenter: parent.verticalCenter
                text: "Вычислить"
                onClicked: {
                    var ax = parseFloat(pointAx.text);
                    var ay = parseFloat(pointAy.text);

                    var bx = parseFloat(pointBx.text);
                    var by = parseFloat(pointBy.text);

                    var cx = parseFloat(pointCx.text);
                    var cy = parseFloat(pointCy.text);

                    var s = 0.5 * Math.abs((bx - ax)*(cy - ay) - (cx - ax)*(by - ay))
                    result_b.text = s
                }
            }
        }
        Rectangle {
            color: "cyan"
            Layout.preferredHeight: 30
            Layout.preferredWidth: 250
            Layout.row: 9
            Layout.column: 0
            Text {
                anchors.centerIn: parent
                text: "Результат:"
            }
        }
        Rectangle {
            color: "cyan"
            Layout.preferredHeight: 30
            Layout.preferredWidth: 250
            Layout.row: 9
            Layout.column: 1
            Text {
                id: result_b
                anchors.centerIn: parent
                text: ""
            }
        }
    }
}
