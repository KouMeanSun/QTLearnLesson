import QtQuick
import QtQuick.Controls
import QtQuick.Window
//import "Config"

Item {
    id: buttonGroup
    implicitWidth: 30 * 3;
    Button{
        id:idtitleBtn
        x: {
            return buttonGroup.width / 2 - idtitleBtn.width/2;
        }
        y:5  //设置纵坐标
        width:80
        height: 30
        text:"我爱上班"   //按钮标题
        contentItem: Text {
            text: idtitleBtn.text
            font: idtitleBtn.font
            opacity: enabled ? 1.0 : 0.3
            color: idtitleBtn.down ? "#17a81a" : "#FFFFFF"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }
        //设置按钮背景颜色
        background: Rectangle {
            color: Qt.rgba(0.58, 0.1, 0.1,1.0);
        }

        //信号槽连接，单击信号
        onClicked: {
            console.log("我被点击了, ")
            CodeImage.setTestImage();
        }

    }
    //最小化
    Button{
        id:minBtn;
        flat: true;
        anchors.right: maxBtn.left;
        icon.width:20; icon.height:20
        icon.source: "qrc:/Images/IconButton/win-minimize.svg"

        background: Rectangle{
            implicitWidth: buttonGroup.height;
            implicitHeight: buttonGroup.height;
            color: {
                if(minBtn.pressed && minBtn.hovered)
                    return Qt.rgba(0.58, 0.1, 0.1,1.0);
                if(minBtn.hovered)
                    return Qt.rgba(0.58, 0.1, 0.1,1.0);
                else
                    return Qt.rgba(0.58, 0.1, 0.1,1.0);
            }
        }

        ToolTip.visible: minBtn.hovered;
        ToolTip.delay: 500;
        ToolTip.text: qsTr("最小化");

        onClicked: {
            mainWindow.visibility = Window.Minimized;
        }
    }
    //最大化
    Button{
        id:maxBtn;
        flat: true;
        anchors.right: closeBtn.left;
        icon.width:20; icon.height:20
        icon.source: {
            if(mainWindow.visibility !== Window.Maximized)
                return "qrc:/Images/IconButton/win-maximize.svg";
            else
                return "qrc:/Images/IconButton/win-restore.svg";
        }

        background: Rectangle{
            implicitWidth: buttonGroup.height;
            implicitHeight: buttonGroup.height;
            color: {
                if(maxBtn.pressed && maxBtn.hovered)
                    return Qt.rgba(0.58, 0.1, 0.1,1.0);
                if(maxBtn.hovered)
                    return Qt.rgba(0.58, 0.1, 0.1,1.0);
                else
                    return Qt.rgba(0.58, 0.1, 0.1,1.0);
            }
        }

        ToolTip.visible: maxBtn.hovered;
        ToolTip.delay: 500;
        ToolTip.text: mainWindow.visibility === Window.Maximized ? qsTr("向下还原"):qsTr("最大化");

        onClicked: {
            mainWindow.visibility = mainWindow.visibility === Window.Maximized ? Window.Windowed : Window.Maximized;
        }
    }
    //关闭
    Button{
        id:closeBtn;
        flat: true;
        anchors.right: parent.right;
        icon.source: "qrc:/Images/IconButton/win-close.svg"
        icon.color: closeBtn.hovered ? "white" : "black"
        icon.width:20; icon.height:20

        background: Rectangle{
            implicitWidth: buttonGroup.height;
            implicitHeight: buttonGroup.height;
            color: {
                if(closeBtn.pressed && closeBtn.hovered)
                    return Qt.rgba(0.58, 0.1, 0.1,1.0);
                if(closeBtn.hovered)
                    return Qt.rgba(0.68, 0.1, 0.1,1.0);
                else
                    return Qt.rgba(0.58, 0.1, 0.1,1.0);
            }
        }

        ToolTip.visible: closeBtn.hovered;
        ToolTip.delay: 500;
        ToolTip.text: qsTr("关闭");

        onClicked: {
            Qt.quit();
        }
    }
}
