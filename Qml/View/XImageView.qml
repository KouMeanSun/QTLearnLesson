import QtQuick 2.15
import custom.qimi.image 1.0

Window {
    title:"ImageView"
    width:360
    height: 640
    Image{
            id:img
            anchors.fill: parent
        }
        Connections{
            target: CodeImage
            onCallQmlRefeshImg:{
                img.source = ""
                img.source = "image://CodeImg"
            }
        }

}
