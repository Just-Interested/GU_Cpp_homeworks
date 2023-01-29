import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import com.my.testclass 1.0

Window {
    id: _mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Tasker")

    GridLayout {
        anchors.fill: parent
        columns: 1
        rows: 3
        TaskList{
            id: _taskList
            Layout.row: 1
            Layout.column: 0
            Layout.fillWidth: parent
            Layout.topMargin: 10
        }
        Connections {
            target: _taskList
            function onTaskProgressChanged(idx, progress){
                _testClass.taskProgressChanged(idx, progress)
            }
        }
        NewTaskWidget {
            id: _newTaskWidget
            Layout.row: 0
            Layout.column: 0
            Layout.fillWidth: parent
            Layout.topMargin: 10
        }
    }
    Connections {
        target: _newTaskWidget
        function onAddNewTask(taskname, progressVal, deadline) {
            _taskList.addTask(taskname, progressVal, deadline)
            _testClass.addNewTask(taskname, progressVal, deadline)
        }
    }
    TestClass {
        id: _testClass
        objectName: "testClass"
        Component.onCompleted: {
            readData()
        }
    }
    Connections {
        target: _testClass
        function onNextTask(taskname, progressVal, deadline){
            _taskList.addTask(taskname, progressVal, deadline)
        }
    }
    onClosing: {
        _testClass.writeData()
//        console.log("Exiting")
    }
}
