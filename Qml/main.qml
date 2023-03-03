import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material.impl as Effect
import Custon.Control

MainWindow {
    id:mainWindow


    flags:Qt.FramelessWindowHint | Qt.Window;
    minimumWidth: 970;
    minimumHeight: 642;
    visible: true
    width:972
    height: 648
    color: Qt.color("#00cc33");

    //最小化函数
    function doMinimized() {
        flags = Qt.Window | Qt.WindowFullscreenButtonHint | Qt.CustomizeWindowHint | Qt.WindowMinimizeButtonHint
        mainWindow.visibility = Window.Minimized
    }

    Effect.BoxShadow{
        anchors.fill: parent
        anchors.margins: 4
        color: "#777777"
        blurRadius: 4

    }



}
