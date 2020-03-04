include(speedtestdotnet.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = speedtestdotnet.h

SOURCES = speedtestdotnet.cpp

TARGET = $$qtLibraryTarget(speedtestdotnet)

DESTDIR = ../../plugins

EXAMPLE_FILES = speedtestdotnet.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


