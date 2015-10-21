import QtQuick 2.4
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.3
import QtQuick.XmlListModel 2.0

TreeView {
    id: tree
    model: repoModel
    itemDelegate: Item {
//       color: "lightblue"
       implicitHeight : 50

       Row {
           anchors.fill: parent
           Image {
               source: "qrc:///images/folder.png"
           }

           Text {
               text: styleData.value
           }
       }
   }

    TableViewColumn {
        title: "Хранилища"
        role: "display"
    }
}
