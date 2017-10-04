import QtQuick 2.6
import QtQuick.Window 2.2

import com.gilzoide.hexagon 0.1
import com.gilzoide.fluidsynth 0.1

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Fluidsynth {
        id: synth
    }

    Hexagon {
        radius: 50
        color: "red"
        antialiasing: true
        Component.onCompleted: {
            synth.setOptions({
                "audio.driver": "jack",
            });
        }
    }
}
