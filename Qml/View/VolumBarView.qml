import QtQuick 2.15

Window {
    width: 640
    height:360
    color:Qt.color("#FFFFFF")

    Rectangle{
        Row{
            Column{
                y: 300
                id: column1
                spacing: 2
                property var value: 4
                Repeater{
                    model: 5

                    Rectangle{
                        height: 4
                        width: 12
                        radius: 2
                        color: index >= column1.value ? "red" : "gray"
                    }

                }
            }

            Column{
                y: 300
                id: column2
                spacing: 2
                property var value: 3
                Repeater{
                    model: 5

                    Rectangle{
                        height: 4
                        width: 12
                        radius: 2
                        color: index >= column2.value ? "red" : "gray"
                    }

                }
            }

        }
    }



}
