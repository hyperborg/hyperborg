/* HyperBorg QML test settings
	-> testing for GAUGEs
*/

import QtQuick 
import QtQuick.Window 
import QtQuick.Controls 
import QtCharts

import HUDButton
import HUDCalendar
bimport HUDCalendarEntry
import HUDClock
import HUDElement
import HUDEventList
import HUDGarbage
import HUDGauge
import HUDHFSTree
import HUDLibrary
import HUDNavigator
import HUDPowerGrid
import HUDScreen
import HUDShoppingList
import HUDTimeTable
import HUDTodoList
import HUDWeather

import "qml" as System

Window{ 
	id: _window 
	visible: true 
	visibility: "FullScreen"
	width : 800 
	height : 600
	title : qsTr("HyperBorg QML Test") 
	color: "black"

/*
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
*/
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
	text: test_heartbeat
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
	height : 400
	x:0
	y:0
}

System.HUDLog 
{
    id: _hudlog
    width : 300
    height : 600
	logline: hfs.system_logline
    x:0
    y:400
}

HUDWeather {
	id: _weather
    objectName: "_weather"
	width:450
	height: 450
	x: 300
	y: 0
}

/*
HUDPowerGrid {
	id: _powergrid
        objectName: "_powergrid"
	width:450
	height: 450
	x: 1450
	y: 0
}
*/

HUDCalendar {
	id: _calendar
	objectName: "_calendar"
	width: 1000
	height: 600
	x: 750
	y: 0
}

/*
HUDTimeTable {
	id: _timetable
    objectName: "_timetable"
	stationName: "PD"
	stationId: "00000000"
	width:600
	height: 300
	x: 750
	y: 0
}

HUDTimeTable {
	id: _2
        objectName: "_timetable2"
	stationName: "Wr"
	stationId: "00000001"
	width:600
	height: 300
	x: 750
	y: 400
}
*/

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
	id: button_kid1
       objectName: "button_kid1"
	text: "KID#1 ROOM"
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
	id: button_kid3
        objectName: "button_kid3"
	text: "KID#3 MIRA"
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
	id: button_kid2
        objectName: "button_kid2"
	text: "KID#2 ROOM"
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


} // Window
