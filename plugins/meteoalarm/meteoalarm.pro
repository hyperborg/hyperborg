include(meteoalarm.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = meteoalarm.h

SOURCES = meteoalarm.cpp

TARGET = $$qtLibraryTarget(meteoalarm)

DESTDIR = ../../plugins

EXAMPLE_FILES = meteoalarm.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


