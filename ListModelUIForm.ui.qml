import QtQuick 2.4
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2

Item {
    property alias listView: listView
    ColumnLayout {
        width: parent.width
        height: parent.height
        ListView {
            id: listView
            width: parent.width
            height: parent.height
            clip: true
            Layout.leftMargin: 20
            Layout.fillHeight: true
            Layout.fillWidth: true
            ScrollBar.vertical: ScrollBar {}
        }
    }
}
