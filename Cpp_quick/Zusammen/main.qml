import QtQuick
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Zussamen")

    ColumnLayout {
        anchors.fill: parent

        // blank top item, used (together with bottom blank item) to center main items
        Item { Layout.fillHeight: true }

        GroupBox {
            title: qsTr("О себе")
            Layout.fillWidth: parent
            Layout.leftMargin: 10
            Layout.rightMargin: 10
            label: Label {
                x: parent.leftPadding
                leftPadding: 10
                rightPadding: 10
                text: parent.title
                background: Rectangle {
                    color: "white"
                }
            }

            GridLayout {
                anchors.fill: parent
                rows: 6
                columns: 2

                Text {
                    text: qsTr("Имя:")
                    horizontalAlignment: Text.AlignRight
                    Layout.row: 0
                    Layout.column: 0
                    Layout.fillWidth: true
                    Layout.maximumWidth: 250
                    Layout.maximumHeight: 30
                    Layout.alignment: Qt.AlignRight
                }

                TextField {
                    id: _name
                    Layout.row: 0
                    Layout.column: 1
                    Layout.fillWidth: true
                    Layout.maximumWidth: 250
                    Layout.maximumHeight: 30
                    Layout.alignment: Qt.AlignLeft
                }

                Text {
                    text: qsTr("Пол:")
                    horizontalAlignment: Text.AlignRight
                    Layout.row: 1
                    Layout.column: 0
                    Layout.fillWidth: true
                    Layout.maximumWidth: 250
                    Layout.maximumHeight: 30
                    Layout.alignment: Qt.AlignRight
                }

                ComboBox {
                    id: _sex
                    editable: false
                    model: [qsTr("Мужской"), qsTr("Женский")]
                    Layout.row: 1
                    Layout.column: 1
                    Layout.fillWidth: true
                    Layout.maximumWidth: 250
                    Layout.maximumHeight: 30
                    Layout.alignment: Qt.AlignLeft
                }

                Text {
                    text: qsTr("Возраст:")
                    horizontalAlignment: Text.AlignRight
                    Layout.row: 2
                    Layout.column: 0
                    Layout.fillWidth: true
                    Layout.maximumWidth: 250
                    Layout.maximumHeight: 30
                    Layout.alignment: Qt.AlignRight
                }

                TextField {
                    id: _age
                    Layout.row: 2
                    Layout.column: 1
                    Layout.fillWidth: true
                    Layout.maximumWidth: 30
                    Layout.maximumHeight: 30
                    Layout.alignment: Qt.AlignLeft
                    inputMask: "DD;_"
                    horizontalAlignment: TextInput.AlignHCenter
                }

                Text {
                    text: qsTr("Образование:")
                    horizontalAlignment: Text.AlignRight
                    Layout.row: 3
                    Layout.column: 0
                    Layout.fillWidth: true
                    Layout.maximumWidth: 250
                    Layout.maximumHeight: 30
                    Layout.alignment: Qt.AlignRight
                }

                TextField {
                    id: _education
                    Layout.row: 3
                    Layout.column: 1
                    Layout.fillWidth: true
                    Layout.maximumWidth: 250
                    Layout.maximumHeight: 30
                    Layout.alignment: Qt.AlignLeft
                }

                Text {
                    text: qsTr("Хобби:")
                    horizontalAlignment: Text.AlignRight
                    Layout.row: 4
                    Layout.column: 0
                    Layout.fillWidth: true
                    Layout.maximumWidth: 250
                    Layout.maximumHeight: 30
                    Layout.alignment: Qt.AlignRight
                }

                GroupBox {
                    id: _hobby
                    Layout.row: 4
                    Layout.column: 1
                    Layout.fillWidth: true
                    Layout.maximumWidth: 250
                    ColumnLayout {
                        RadioButton {
                            id: _hobby_true
                            text: qsTr("Есть")
                            checked: true
                        }
                        RadioButton {
                            id: _hobby_false
                            text: qsTr("Какое хобби?!\nУ людей бывает свободное вркмя?")
                            Layout.maximumWidth: 230

                        }
                    }
                }

                Text {
                    text: qsTr("Город:")
                    horizontalAlignment: Text.AlignRight
                    Layout.row: 5
                    Layout.column: 0
                    Layout.fillWidth: true
                    Layout.maximumWidth: 250
                    Layout.maximumHeight: 30
                    Layout.alignment: Qt.AlignRight
                }

                TextField {
                    id: _town
                    Layout.row: 5
                    Layout.column: 1
                    Layout.fillWidth: true
                    Layout.maximumWidth: 250
                    Layout.maximumHeight: 30
                    Layout.alignment: Qt.AlignLeft
                }

                Text {
                    text: qsTr("О себе:")
                    horizontalAlignment: Text.AlignRight
                    Layout.row: 6
                    Layout.column: 0
                    Layout.fillWidth: true
                    Layout.maximumWidth: 250
                    Layout.maximumHeight: 30
                    Layout.alignment: Qt.AlignRight
                }

                TextField {
                    id: _myself
                    Layout.row: 6
                    Layout.column: 1
                    Layout.fillWidth: true
                    Layout.maximumWidth: 250
                    Layout.maximumHeight: 30
                    Layout.alignment: Qt.AlignLeft
                }
            }
        }

        GroupBox {
            title: qsTr("Поиск партнера")
            Layout.fillWidth: parent
            Layout.leftMargin: 10
            Layout.rightMargin: 10
            label: Label {
                x: parent.leftPadding
                leftPadding: 10
                rightPadding: 10
                text: parent.title
                background: Rectangle {
                    color: "white"
                }
            }

            GridLayout {
                anchors.fill: parent
                rows: 3
                columns: 2

                Text {
                    text: qsTr("Возраст:")
                    horizontalAlignment: Text.AlignRight
                    Layout.row: 0
                    Layout.column: 0
                    Layout.fillWidth: true
                    Layout.maximumWidth: 250
                    Layout.maximumHeight: 30
                    Layout.alignment: Qt.AlignRight
                }

                RowLayout {
                    Layout.row: 0
                    Layout.column: 1
                    Layout.fillWidth: true
                    Layout.maximumWidth: 250
                    Layout.maximumHeight: 30
                    Layout.alignment: Qt.AlignLeft
                    TextField {
                        id: _target_age_from
                        Layout.maximumWidth: 30
                        inputMask: "DD;_"
                        horizontalAlignment: TextInput.AlignHCenter
                    }
                    Text {
                        text: "-"
                    }
                    TextField {
                        id: _target_age_to
                        Layout.maximumWidth: 30
                        inputMask: "DD;_"
                        horizontalAlignment: TextInput.AlignHCenter
                    }
                    Item { Layout.fillWidth: true }
                }

                Text {
                    text: qsTr("Пол:")
                    horizontalAlignment: Text.AlignRight
                    Layout.row: 1
                    Layout.column: 0
                    Layout.fillWidth: true
                    Layout.maximumWidth: 250
                    Layout.maximumHeight: 30
                    Layout.alignment: Qt.AlignRight
                }

                ComboBox {
                    id: _target_sex
                    editable: false
                    model: [ qsTr("Женский"), qsTr("Мужской")]
                    Layout.row: 1
                    Layout.column: 1
                    Layout.fillWidth: true
                    Layout.maximumWidth: 250
                    Layout.maximumHeight: 30
                    Layout.alignment: Qt.AlignLeft
                }

                Text {
                    text: qsTr("Образование:")
                    horizontalAlignment: Text.AlignRight
                    Layout.row: 2
                    Layout.column: 0
                    Layout.fillWidth: true
                    Layout.maximumWidth: 250
                    Layout.maximumHeight: 30
                    Layout.alignment: Qt.AlignRight
                }

                TextField {
                    id: _target_education
                    Layout.row: 2
                    Layout.column: 1
                    Layout.fillWidth: true
                    Layout.maximumWidth: 250
                    Layout.maximumHeight: 30
                    Layout.alignment: Qt.AlignLeft
                }
            }
        }

        Button {
            Layout.alignment: Qt.AlignHCenter
            Layout.topMargin: 20
            Layout.preferredHeight: 30
            Layout.preferredWidth: 150
            text: qsTr("Регистрация")
            onClicked: {
                console.log("Имя: " + _name.text)
                console.log("Пол: " + _sex.currentText)
                console.log("Возраст: " + _age.text)
                console.log("Образование: " + _education.text)
                console.log("Город: " + _town.text)
                console.log("О себе: " + _myself.text)
                var s
                if (_hobby_true.checked === true){
                    s = _hobby_true.text
                }
                else {
                    s = _hobby_false.text
                }
                console.log("Хобби: " + s)
                console.log("Возраст партнера: " + _target_age_from.text + "-" + _target_age_to.text)
                console.log("Пол партнера : " + _target_sex.currentText)
                console.log("Образование партнера : " + _target_education.text)
            }
        }

        // blank bottom item, used (together with top blank item) to center main items
        Item { Layout.fillHeight: true }
    }
}
