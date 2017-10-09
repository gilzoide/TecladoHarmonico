import QtQuick 2.6
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import com.gilzoide.jack 0.1

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Teclado Harmônico")

    footer: ToolBar {
        RowLayout {
            anchors.fill: parent
        }
    }

    Jack {
        id: jack
        onConnectionError: console.log(error)
    }

    Keyboard {
        radius: 30
        numLines: 5

        onKeyOn: jack.noteOn(index)
        onKeyOff: jack.noteOff(index)
    }
}
