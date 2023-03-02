import QtQuick
import QtCharts 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import my.new.ChartClass


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Chart Example")

    ChartClass {
        id: _chart_class
        parameter: "Math functions"
        onChartTypeChanged: {
            _chart_class.changeType(_chart_class.chartType)
            _line_chart.redraw()
        }
    }

    GridLayout {
        id: _grid_lay
        anchors.fill: parent
        columns: 2
        rows: 7

        ChartView {
            id: _line_chart

            Layout.fillWidth: parent
            Layout.fillHeight: parent
            Layout.rowSpan: _grid_lay.rows
            Layout.row: 0
            Layout.column: 0

            title: _chart_class.parameter
            antialiasing: true
            LineSeries {
                id: _line_series
                color: _chart_class.color
                axisX: ValuesAxis {
                    id: _x_axis
                    min:0
                    max: 5
                }
                axisY: ValuesAxis {
                    id: _y_axis
                    min: -1
                    max: 1
                }
            }

            function redraw(){
                // Очищаем график
                _line_series.removePoints(0, _line_series.count)

                // Получаем обновленные данные
                var x_values = _chart_class.x_values
                var y_values = _chart_class.y_values

                // Добавляем новые значения на график
                for (var i = 0; i < x_values.length; i++) {
                    var c_x = parseFloat(x_values[i].toFixed(5))
                    var c_y = parseFloat(y_values[i].toFixed(5))
                    if (c_x === Number.NEGATIVE_INFINITY || c_x === Number.POSITIVE_INFINITY || Number.isNaN(c_x))
                        continue
                    if (c_y === Number.NEGATIVE_INFINITY || c_y === Number.POSITIVE_INFINITY || Number.isNaN(c_y))
                        continue
                    _line_series.append(c_x, c_y)
                }

                // Для масштабирования графика, запоминаем минимальные и максимальные значения
                var max_x = _line_series.at(0).x
                var min_x = max_x
                var max_y = _line_series.at(0).y
                var min_y = max_y
                for (i = 0; i < _line_series.count; i++){
                    c_x = _line_series.at(i).x
                    c_y = _line_series.at(i).y
                    min_x = (min_x < c_x) ? min_x : c_x
                    min_y = (min_y < c_y) ? min_y : c_y
                    max_x = (max_x > c_x) ? max_x : c_x
                    max_y = (max_y > c_y) ? max_y : c_y
                }
                _x_axis.min = min_x
                _y_axis.min = min_y
                _x_axis.max = max_x
                _y_axis.max = max_y
            }

            Component.onCompleted: {
                redraw()
            }
        }

        Item {
            Layout.fillHeight: parent
            Layout.row: 0
            Layout.column: 1
        }

        Button {
            Layout.column: 1
            Layout.row: 1
            Layout.preferredWidth: 150
            Layout.preferredHeight: 30
            Layout.margins: 10
            text: "y = sin(x)"
            onClicked: {
                _chart_class.chartType = ChartClass.Sin_chart
            }
        }

        Button {
            Layout.column: 1
            Layout.row: 2
            Layout.preferredWidth: 150
            Layout.preferredHeight: 30
            Layout.margins: 10
            text: "y = x"
            onClicked: {
                _chart_class.chartType = ChartClass.Equel_chart
            }
        }

        Button {
            Layout.column: 1
            Layout.row: 3
            Layout.preferredWidth: 150
            Layout.preferredHeight: 30
            Layout.margins: 10
            text: "y =|x - 2.5|"
            onClicked: {
                _chart_class.chartType = ChartClass.Mod_chart
            }
        }

        Button {
            Layout.column: 1
            Layout.row: 4
            Layout.preferredWidth: 150
            Layout.preferredHeight: 30
            Layout.margins: 10
            text: "y = x^2"
            onClicked: {
                _chart_class.chartType = ChartClass.Square_chart
            }
        }

        Button {
            Layout.column: 1
            Layout.row: 5
            Layout.preferredWidth: 150
            Layout.preferredHeight: 30
            Layout.margins: 10
            text: "y = log2(x)"
            onClicked: {
                _chart_class.chartType = ChartClass.Log2_chart
            }
        }

        Item {
            Layout.fillHeight: parent
            Layout.row: _grid_lay.rows - 1
            Layout.column: 1
        }

    }
}
