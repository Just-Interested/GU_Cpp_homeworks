import QtQuick
import QtCharts 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("LSS")

    ChartView {
        id: _chart_view
        anchors.fill: parent
        title: "Linear approximation"

        ScatterSeries {
            axisX: ValuesAxis {
                id: _x_axis
                min: 0
                max: 210
            }
            axisY: ValuesAxis {
                id: _y_axis
                min: 0
                max: 30
            }
            id: _scatter_series
            XYPoint {x:7; y:13}
            XYPoint {x:31; y:10}
            XYPoint {x:61; y:9}
            XYPoint {x:99; y:10}
            XYPoint {x:129; y:12}
            XYPoint {x:178; y:20}
            XYPoint {x:209; y:26}
        }

        LineSeries {
            id: _line_series
        }

        function approximate(){
            // init
            var sum_x = 0.0
            var sum_y = 0.0
            var sum_XX = 0.0
            var sum_XY = 0.0

            // calc
            var n = _scatter_series.count
            for (var i = 0; i < n; i++){
                var c_x = _scatter_series.at(i).x
                var c_y = _scatter_series.at(i).y
                sum_x += c_x
                sum_y += c_y
                sum_XX += c_x * c_x
                sum_XY += c_x * c_y
            }
            var a = (n * sum_XY - sum_x * sum_y) / (n * sum_XX - sum_x * sum_x)
            var b = (sum_y - a * sum_x) / n

            // draw
            // y = ax + b
            var x = 0
            var n_steps = 10
            var step = _x_axis.max / n_steps
            for (i = 0; i < n_steps + 1; i++) {
                var y = a * x + b
                _line_series.append(x, y)
                x += step
            }
        }

        Component.onCompleted: {
            approximate()
        }
    }
}
