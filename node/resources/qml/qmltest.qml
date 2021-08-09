import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
 
Window {
    visible: false
    width: 640
    height: 480
    title: qsTr("QML TEST SCREEN")
 
    Label {
        id: labelCount
        text: "0"
    }
 
    Button {
        text: qsTr("Simple button")
    }
}