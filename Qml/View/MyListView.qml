import QtQuick 2.15

Window {
    title:"ListView"
    width:360
    height: 640
    ListView {
        width:200
        height:300
        model: dataSource
        delegate: Text {
            text:"Animal:"+ type + ", size:"+size
        }
    }

}

