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

Window{ 
	id: _window 
	visible: true 
//	visibility: "FullScreen"
	width : 640 
	height : 480 
	title : qsTr("HyperBorg QML Test") 
	color: "black"

/*	

HUDGauge { 
   id: _gauge
   objectName: "_gauge"
   mainMode : 1    
   anchors.top: parent.top 
   anchors.left: parent.left 
   x: 0
   y: 0
   width: 250
   height: 250 
   value: slider.value 
} 

HUDGauge { 
   id: _gauge2
   mainMode : 2 
   anchors.top: parent.top 
   x: 270  
   y: 0
   width: 250 
   height: 250 
} 

HUDGauge { 
   id: _gauge3
   mainMode : 3 
   anchors.top: parent.top 
   x: 540
   y: 0
   width: 250 
   height: 250 
} 

HUDGauge { 
   id: _gauge4
   mainMode : 4    
   anchors.left: parent.left 
   x:0
   y:270
   width: 250 
   height: 250 
   value: slider.value 
} 

HUDGauge { 
   id: _gauge5
   mainMode : 5 
   x: 270  
   y: 270
   width: 250 
   height: 250 
} 

HUDGauge { 
   id: _gauge6
   mainMode : 6 
   x: 540
   y: 270
   width: 250 
   height: 250 
} 

Slider {
    id : slider 
    from: -10
    value : 23    
    to : 50   
    x: 0  
    y: 600  
}

HUDButton {
	id: _button1
        objectName: "_button1"
	text: "ROOM 1"
	width:100
	height: 100
	x: 800
	y:0

	MouseArea {
            anchors.fill: parent // set mouse area (i.e. covering the entire rectangle.)
            acceptedButtons:  Qt.AllButtons
		}	
	}

HUDButton {
	id: _button2
        objectName: "_button2"
	text: "ROOM 2"
	width:200
	height: 200
	x: 1000
	y:0

	MouseArea {
            anchors.fill: parent // set mouse area (i.e. covering the entire rectangle.)
            acceptedButtons:  Qt.AllButtons
            onClicked: {
                _button2.mousePressed(mouseX, mouseY, 0)
			}
		}
	}

HUDButton {
	id: _button3
	objectName: "_button3"
	text: "ROOM 3"
	width:200
	height: 200
	x: 1200
	y:0

	colorOn: "green"
	colorOff: "black"
	colorPending: "orange"
	colorForbidden: "red"

	MouseArea {
            anchors.fill: parent // set mouse area (i.e. covering the entire rectangle.)
            acceptedButtons:  Qt.AllButtons
            onClicked: {
                _button3.mousePressed(mouseX, mouseY, 0)
			}
		}
	}
*/

HUDClock {
	id : _clock1
	objectName: "clock"
	width : 300
	height : 1000
	x:0
	y:0
}

HUDButton {
	id: _weather
    objectName: "_weather"
	text: "WEATHER"
	width:450
	height: 450
	x: 300
	y: 0
}

HUDButton {
	id: _hall
    objectName: "_hall"
	text: "HALL"
	width:150
	height: 150
	x: 300
	y: 450
}

HUDButton {
	id: _bedroom
    objectName: "_bedroom"
	text: "BEDROOM"
	width:150
	height: 150
	x: 300
	y: 600
}

HUDButton {
	id: _front
    objectName: "_front"
	text: "FRONT"
	width:150
	height: 150
	x: 300
	y: 750
}

HUDButton {
	id: lroom
    objectName: "_lroom"
	text: "LROOM"
	width:150
	height: 150
	x: 450
	y: 450
}

HUDButton {
	id: _pete
    objectName: "_pete"
	text: "PETE"
	width:150
	height: 150
	x: 450
	y: 600
}

HUDButton {
	id: _toilet
    objectName: "_toilet"
	text: "TOILET"
	width:150
	height: 150
	x: 450
	y: 750
}

HUDButton {
	id: kitchen
    objectName: "_kitchen"
	text: "KITCHEN"
	width:150
	height: 150
	x: 600
	y: 450
}

HUDButton {
	id: conserv
    objectName: "_converv"
	text: "Conserv."
	width:150
	height: 150
	x: 600
	y: 600
}

HUDButton {
	id: bathroom
    objectName: "_bathroom"
	text: "BATHROOM"
	width:150
	height: 150
	x: 600
	y: 750
}

} // Window
