import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

ApplicationWindow {
    title: qsTr("Hello World")
    width: 640
    height: 480
    visible: true

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: messageDialog.show(qsTr("Open action triggered"));
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }
    toolBar: ToolBar {
        RowLayout {
            anchors.fill: parent
            ToolButton {
                iconSource: "qrc:///images/refresh.png"
            }
            ToolButton {
                iconSource: "qrc:///images/arrow-up.png"
            }
            TextField {
                Layout.fillWidth: true
            }
            ToolButton {
                iconSource: "qrc:///images/go.png"
            }
        }
    }
    SplitView {
        anchors.fill: parent
        RepoPanel {

        }

        ListView {

        }
    }
}
