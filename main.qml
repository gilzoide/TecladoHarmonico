import QtQuick 2.6
import QtQuick.Window 2.2

import com.gilzoide.hexagon 0.1

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Hexagon {
        raio: 50
        cor: "red"
        antialiasing: false
        onRaioChanged: console.log("Novo raio: " + raio)
    }
}
