import QtQuick
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import "qrc:/MyShapes.js" as Shapes

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Painter")

    ColumnLayout {
        anchors.fill: parent
        ComboBox {
            id: _shapeBox
            Layout.alignment: Qt.AlignHCenter
            model: ["star", "ring", "house", "hourglass"]
            onCurrentTextChanged: {
                _canvas.requestPaint()
            }
        }

        Canvas {
            id: _canvas
//            anchors.fill: parent
            Layout.fillHeight: parent
            Layout.fillWidth: parent
            property int xStep: width / 6
            property int yStep: height / 5
            onPaint: {
                var ctx = getContext("2d");
                ctx.clearRect(0, 0, width, height);
                ctx.beginPath()
                var points = Shapes.getShapePoints(_shapeBox.currentText, parent.width/2, parent.height/2, 2);
                points.forEach(function (element){
                    ctx.lineTo(element[0], element[1]);
                })
                ctx.closePath()
                ctx.lineWidth = 3;
                ctx.stroke();
            }
        }
    }

}
