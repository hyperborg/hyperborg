/* HyperBorg QML test settings
	-> testing for GAUGEs
*/

import QtQuick 
import QtQuick.Window 
import QtQuick.Controls 
import QtCharts
import HUDGauge 
import HUDButton
import HUDClock
import HUDWeather
import HUDGarbage
import HUDPowerGrid
import HUDTimeTable

Window{ 
	id: _window 
	visible: true 
	visibility: "FullScreen"
	width : 800 
	height : 600 
	title : qsTr("HyperBorg QML Test") 
	color: "black"

	MultiPointTouchArea
	{
	    anchors.fill : parent
	    touchPoints: [
		TouchPoint { id: point1 },
		TouchPoint { id: point2 }
	    ]

	    property string act_id
	    property Item litem
	    property bool ps
	    property bool ps2

	    onGestureStarted : 
	    {
		console.log("ongestureStarted")
		litem = _window.contentItem.childAt(point1.x, point1.y)
		if (litem)
		{
		    console.log("Item was hit", litem)
		}
	    }

	    onTouchUpdated:
	    { 
		console.log("onTouchUpdated") 
		if (litem)
		{
		    ps   = (point1.x-point1.previousX)
		    ps2  = (point2.x-point2.previousX)
		    console.log("PS: ", ps, "  PS2:", ps2)

		    if (point2.pressed==false)
 		    {
			    litem.x = litem.x+point1.x-point1.previousX
			    litem.y = litem.y+point1.y-point1.previousY
		    }
		    else
		    {
		        if (ps == ps2)
			{
			    litem.x = litem.x+point1.x-point1.previousX
			    litem.y = litem.y+point1.y-point1.previousY
			}
			else
			{
	    	    	    litem.rotation = litem.rotation - point1.x-point1.previousX
			    console.log("New rotation:", point1.rotation, "PS: ", ps, "  PS2:", ps2)
			}
		    }
		}
	    }

	    onUpdated:
	    {
		console.log("onUpdated")
	    }

	    onReleased:
	    {
		console.log("onReleased")
	    }
	}

HUDClock {
	id : _clock1
	objectName: "clock"
	width : 300
	height : 1000
	x:0
	y:0
}

HUDWeather {
	id: _weather
    objectName: "_weather"
	width:450
	height: 450
	x: 300
	y: 0
}

HUDTimeTable {
	id: _timetable
        objectName: "_timetable"
	stationName: "Pottendorf"
	stationId: "1130626"
	width:600
	height: 300
	x: 750
	y: 0
}

HUDTimeTable {
	id: _2
        objectName: "_timetable2"
	stationName: "Wr.Neustadt"
	stationId: "8100516"
	width:600
	height: 300
	x: 750
	y: 400
}

TreeView {
	delegate: TreeViewDelegate {}
	width: 600
	height:900
	x:1400
	y:0
        model: hfs
}

HUDButton {
	id: button_szhalo
    objectName: "button_szhalo"
	text: "SZ.HALO"
	width:150
	height: 150
	x: 300
	y: 450

	colorOn: "red"
	colorOff: "green"
	colorPending: "orange"
	colorForbidden: "red"
	button: "button.1_1"
	value : hfs.switch_1_1

	MouseArea {
            anchors.fill: parent // set mouse area (i.e. covering the entire rectangle.)
            acceptedButtons:  Qt.AllButtons
            onClicked: {
                button_szhalo.mousePressed(mouseX, mouseY, 0)
			}
		}
	}

HUDButton {
	id: button_szfurdo
    objectName: "button_szfurdo"
	text: "SZ.FURDO"
	width:150
	height: 150
	x: 450
	y: 450

	colorOn: "red"
	colorOff: "green"
	colorPending: "orange"
	colorForbidden: "red"
	button: "button.1_0"
	value : hfs.switch_1_0

	MouseArea {
            anchors.fill: parent 
            acceptedButtons:  Qt.AllButtons
            onClicked: {
                button_szfurdo.mousePressed(mouseX, mouseY, 0)
			}
		}
	}


HUDButton {
	id: button_bence
        objectName: "button_bence"
	text: "BENCE"
	width:150
	height: 150
	x: 600
	y: 450

	colorOn: "red"
	colorOff: "green"
	colorPending: "orange"
	colorForbidden: "red"
	button: "button.1_2"
	value : hfs.switch_1_2

	MouseArea {
            anchors.fill: parent 
            acceptedButtons:  Qt.AllButtons
            onClicked: {
                button_bence.mousePressed(mouseX, mouseY, 0)
			}
		}
	}


HUDButton {
	id: button_mira
        objectName: "button_mira"
	text: "MIRA" 
	width:150
	height: 150
	x: 300
	y: 600

	colorOn: "red"
	colorOff: "green"
	colorPending: "orange"
	colorForbidden: "red"
	button: "button.1_3"
	value : hfs.switch_1_3

	MouseArea {
            anchors.fill: parent 
            acceptedButtons:  Qt.AllButtons
            onClicked: {
                button_mira.mousePressed(mouseX, mouseY, 0)
			}
		}
}

HUDButton {
	id: button_bogi
        objectName: "button_bogi"
	text: "BOGI"
	width:150
	height: 150
	x: 450
	y: 600

	colorOn: "red"
	colorOff: "green"
	colorPending: "orange"
	colorForbidden: "red"
	button: "button.1_4"
	value : hfs.switch_1_4

	MouseArea {
            anchors.fill: parent 
            acceptedButtons:  Qt.AllButtons
            onClicked: {
                button_bogi.mousePressed(mouseX, mouseY, 0)
			}
		}
	}

HUDButton {
	id: button_szwc
    objectName: "button_szwc"
	text: "SZ.WC"
	width:150
	height: 150
	x: 600
	y: 600

	colorOn: "red"
	colorOff: "green"
	colorPending: "orange"
	colorForbidden: "red"
	button: "button.1_5"
	value : hfs.switch_1_5

	MouseArea {
            anchors.fill: parent 
            acceptedButtons:  Qt.AllButtons
            onClicked: {
                button_szwc.mousePressed(mouseX, mouseY, 0)
			}
		}
	}

HUDButton {
	id: button_xx
       objectName: "button_xx"
	text: IRODA
	width:150
	height: 150
	x: 300
	y: 750

	colorOn: "red"
	colorOff: "green"
	colorPending: "orange"
	colorForbidden: "red"
	button: "button.1_7"
	value : hfs.switch_1_7

	MouseArea {
            anchors.fill: parent 
            acceptedButtons:  Qt.AllButtons
            onClicked: {
                button_xx.mousePressed(mouseX, mouseY, 0)
			}
		}
	}

/*
HUDButton {
	id: button_xx
    objectName: "button_xx"
	text: "BUTTON XX"
	width:150
	height: 150
	x: 600
	y: 450

	colorOn: "red"
	colorOff: "green"
	colorPending: "orange"
	colorForbidden: "red"
	button: "button.1_2"
	switchValue : "switch.1_2"

	MouseArea {
            anchors.fill: parent 
            acceptedButtons:  Qt.AllButtons
            onClicked: {
                button_xx.mousePressed(mouseX, mouseY, 0)
			}
		}
	}
	*/


} // Window
