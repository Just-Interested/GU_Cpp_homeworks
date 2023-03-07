import QtQuick
import QtQuick.Controls 2.15

Rectangle {
    anchors.fill: parent
    color: "red"
    signal toNextPage(int page_id)
    property int page_id: 1
    property int n_pages_total: 2

    Button {
        id: _next
        anchors.centerIn: parent
        width: 150
        height: 30
        text: "Next"
        onClicked: {
            parent.toNextPage((parent.page_id + 1) % n_pages_total)
            parent.destroy(100)
        }
    }
}
