import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material.impl as Effect
import Custon.Control
import "View"

MainWindow {
    id:mainWindow
    flags:Qt.FramelessWindowHint | Qt.Window;
    minimumWidth: 970;
    minimumHeight: 642;
    visible: true
    width:972
    height: 648
//    color: Qt.color("#000000");

    //最小化函数
    function doMinimized() {
        flags = Qt.Window | Qt.WindowFullscreenButtonHint | Qt.CustomizeWindowHint | Qt.WindowMinimizeButtonHint
        mainWindow.visibility = Window.Minimized
    }

    Effect.BoxShadow{
        anchors.fill: parent
        anchors.margins: 0
        color: Qt.rgba(0,1,0,1);
//        blurRadius: 4
    }

    Component {
        id: contactDelegate
        Item {
            width: 180; height: 70
            Column {
                Text { text: '<b>Name:</b> ' + name }
                Button{
                    width: parent.width
                    height:40
                    text: name
                    onClicked: function(){

                        if(number === "1"){
                            idXImageView.show();
                            CodeImage.setTestImage();
                        }else if(number === "2"){
                            idMyListView.show();
                        }else if(number === "3"){
                            idVolumBarView.show();
                        }

                    }
                }
            }
        }
    }

    ListView {

        x:100
        y:100
        width: 180; height: 200

        model: ContactModel {}
        delegate: contactDelegate
        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        focus: true
    }

    XImageView{
        id:idXImageView
    }

    MyListView{
        id:idMyListView
    }
    VolumBarView{
        id:idVolumBarView
    }

    Rectangle{
        height: 36
        width: parent.width
        anchors.margins: mainWindow.visibility === Window.Maximized ? 0 : 6
        color: Qt.color("#00cc33");
        visible: true
        //标题栏
        Rectangle {
            id: windowTitleBar
            height: 36
            color: Qt.rgba(0,0,1,1);
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right;

            MouseArea{
                property point offset;
                anchors.fill: parent;
                cursorShape: Qt.SizeAllCursor;
                onPressed: function(mouse){
                    var clickPos = mapToGlobal(mouse.x, mouse.y);
                    offset.x = clickPos.x - mainWindow.x;
                    offset.y = clickPos.y - mainWindow.y;
                }
                onPositionChanged: function(mouse){
                    var currentPos = mapToGlobal(mouse.x, mouse.y);
                    mainWindow.x = currentPos.x - offset.x;
                    mainWindow.y = currentPos.y - offset.y;
                }
            }

            RowLayout{
                anchors.fill: parent

                WindowButton{
                    anchors.fill: parent
                }
            }
        }
    }
}
