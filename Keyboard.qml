import QtQuick 2.0

Item {
    id: board
    property real radius: 20
    property int numColumns: 10
    property int numLines: 10

    // Transform a (x, y) index into a scalar one
    function getIndex(x, y) {
        return y * numColumns + x;
    }

    Repeater {
        model: numLines * numColumns
        Key {
            readonly property int iLin: index / numColumns
            readonly property int iCol: index % numColumns

            x: iCol * S
            y: iLin * H + (iCol % 2 == 0 ? 0 : H / 2);
            radius: board.radius
            Text {
                anchors.centerIn: parent
                text: index
            }
        }
    }
}
