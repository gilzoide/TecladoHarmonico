import QtQuick 2.0
import com.gilzoide.hexagon 0.1

Hexagon {
    /// Should Hexagon's colors be toggled?
    property bool pressed: false

    function toggle() {
        pressed = !pressed;
        return pressed;
    }
}
