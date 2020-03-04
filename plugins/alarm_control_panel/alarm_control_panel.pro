include(alarm_control_panel.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = alarm_control_panel.h

SOURCES = alarm_control_panel.cpp

TARGET = $$qtLibraryTarget(alarm_control_panel)

DESTDIR = ../../plugins

EXAMPLE_FILES = alarm_control_panel.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


