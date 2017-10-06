import QtQuick 2.6
import QtQuick.Window 2.2
import com.gilzoide.fluidsynth 0.1

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Teclado Harmônico")

    Fluidsynth {
        id: synth
        Component.onCompleted: {
            setOptions({
                "audio.driver": "jack",
            });
        }
    }

    Keyboard {
        radius: 30
        numLines: 5
    }
}
