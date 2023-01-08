import QtQuick 

Item 
{
	id: container
	property string logline
	Rectangle
	{
		anchors.fill: parent
		TextArea {
			id : _hudlog
			objectName: "hudlog"
 			anchors.fill:parent
			width : 300
			height : 600
			x:0
			y:400
		}

	}
	
 	onLoglineChanged: {
		_hudlog.text = _hudlog.text + logline
	}
}