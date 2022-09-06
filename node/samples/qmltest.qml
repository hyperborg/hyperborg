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
//	visibility: "FullScreen"
	width : 640 
	height : 480 
	title : qsTr("HyperBorg QML Test") 
	color: "black"

HUDGauge { 
   id: _gauge
   objectName: "_gauge"
   mainMode : 1    
   width: 150
   height: 150 
   // value: slider.value 
   x: 750
   y: 500
} 

HUDGauge { 
   id: _gauge2
   mainMode : 2 
   width: 150 
   height: 150 
   x: 900
   y: 500
} 

HUDGauge { 
   id: _gauge3
   mainMode : 3 
   width: 150 
   height: 150 
   x: 1050
   y: 500
   
} 

HUDGauge { 
   id: _gauge4
   mainMode : 4    
   width: 150 
   height: 150 
   // value: slider.value 
   x:750
   y:650
} 

HUDGauge { 
   id: _gauge5
   mainMode : 5 
   width: 150 
   height: 150 
   x: 900  
   y: 650
} 

HUDGauge { 
   id: _gauge6
   mainMode : 6 
   width: 150 
   height: 150 
   x: 1050
   y: 650
} 

/*
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

HUDWeather {
	id: _weather
    objectName: "_weather"
	width:450
	height: 450
	x: 300
	y: 0
}

HUDPowerGrid {
	id: _powergrid
    objectName: "_powergrid"
	width:450
	height: 450
	x: 1450
	y: 0
}


HUDTimeTable {
	id: _timetable
    objectName: "_timetable"
	width:600
	height: 300
	x: 750
	y: 0
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
	id: _hall
    objectName: "_hall"
	text: "HALL"
	width:150
	height: 150
	x: 300
	y: 450
}

HUDButton {
	id: _kitchen1
    objectName: "_kitchen1"
	text: "KITCHEN1"
	width:150
	height: 150
	x: 300
	y: 600
}

HUDButton {
	id: _roof
    objectName: "_roof"
	text: "ROOF"
	width:150
	height: 150
	x: 300
	y: 750
}

HUDButton {
	id: _passage
    objectName: "_passage"
	text: "PASSAGE"
	width:150
	height: 150
	x: 450
	y: 450
}

HUDButton {
	id: _kitchen2
    objectName: "_kitchen2"
	text: "KITCHEN2"
	width:150
	height: 150
	x: 450
	y: 600
}

HUDButton {
	id: _toilet
    objectName: "_movie"
	text: "MOVIE"
	width:150
	height: 150
	x: 450
	y: 750
}

HUDButton {
	id: _perimeter
    objectName: "_perimeter"
	text: "PERIMETER"
	width:150
	height: 150
	x: 600
	y: 450
}

HUDButton {
	id: _kitchen3
    objectName: "_kitchen3"
	text: "KITCHEN3"
	width:150
	height: 150
	x: 600
	y: 600
}

HUDButton {
	id: _heating
    objectName: "_heating"
	text: "HEATING"
	width:150
	height: 150
	x: 600
	y: 750
}

} // Window
