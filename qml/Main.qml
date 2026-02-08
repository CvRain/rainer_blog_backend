import Nandina.Components
import Nandina.Icon
import Nandina.Theme
import Nandina.Window
import QtQuick
import QtQuick.Layouts

NandinaWindow {
    width: 800
    height: 600
    visible: true
    title: "Rainer Blog Dashboard"

    NanButton {
        width: 350
        height: 45
        text: "一个简单的按钮"
        autoFitText: true
        type: "outlinedPrimary"
        manualFontSize: 18

        anchors.centerIn: parent
    }
}
