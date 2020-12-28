import QtQuick 2.0

Rectangle {
    id:root
    width: 50
    height: 50
    radius: 25
    color: "gray"
    border.color: "red"
    border.width: 1


    Text {
        id: ele
        text: "text"
        font.pointSize: 12
        anchors.fill: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }


}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
