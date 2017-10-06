import QtQuick 2.0
import com.gilzoide.hexagon 0.1

Item {
    id: board
    property real radius: 20
    property int numColumns: 10
    property int numLines: 10
    property color lineColor: "black"
    property color fillColor: "white"

    readonly property real w: 2 * radius
    readonly property real s: 1.5 * radius
    readonly property real h: Math.sqrt(3) * radius

    implicitHeight: numLines * w
    implicitWidth: numColumns * s + radius / 2

    // Transform a (x, y) position into a Hexagon index. See: http://blog.ruslans.com/2011/02/hexagonal-grid-math.html
    function getIndex(x, y) {
        var it = Math.floor(x / s);
        var yts = y - (it % 2) * h / 2;
        var jt = Math.floor(yts / h);
        var xt = x - it * s;
        var yt = yts - jt * h;
        if(xt <= radius * Math.abs(0.5 - yt / h)) {
            it--;
            jt = jt - (it % 2) + (yt > h / 2 ? 1 : 0);
        }
        if(it < 0 || it >= numColumns || jt < 0 || jt >= numLines) {
            return -1;
        }
        return jt * numColumns + it;
    }

    Repeater {
        id: keys
        model: numLines * numColumns
        Key {
            readonly property int iLin: index / numColumns
            readonly property int iCol: index % numColumns

            x: iCol * s
            y: iLin * h + (iCol % 2) * h / 2;
            lineColor: board.lineColor
            fillColor: pressed ? board.lineColor : board.fillColor
            radius: board.radius
            Text {
                anchors.centerIn: parent
                color: pressed ? board.fillColor : board.lineColor
                text: index
            }
        }
    }

    MouseArea {
        anchors.fill: board
        onClicked: {
            var index = getIndex(mouse.x, mouse.y);
            var hex = keys.itemAt(index);
            if(hex) {
                hex.toggle();
                hex.update();
            }
        }
    }
}
