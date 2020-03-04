include(yale_smart_alarm.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = yale_smart_alarm.h

SOURCES = yale_smart_alarm.cpp

TARGET = $$qtLibraryTarget(yale_smart_alarm)

DESTDIR = ../../plugins

EXAMPLE_FILES = yale_smart_alarm.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


