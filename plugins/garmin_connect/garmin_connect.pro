include(garmin_connect.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = garmin_connect.h

SOURCES = garmin_connect.cpp

TARGET = $$qtLibraryTarget(garmin_connect)

DESTDIR = ../../plugins

EXAMPLE_FILES = garmin_connect.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


