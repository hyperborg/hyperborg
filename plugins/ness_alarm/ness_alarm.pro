include(ness_alarm.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ness_alarm.h

SOURCES = ness_alarm.cpp

TARGET = $$qtLibraryTarget(ness_alarm)

DESTDIR = ../../plugins

EXAMPLE_FILES = ness_alarm.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


