include(heatmiser.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = heatmiser.h

SOURCES = heatmiser.cpp

TARGET = $$qtLibraryTarget(heatmiser)

DESTDIR = ../../plugins

EXAMPLE_FILES = heatmiser.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


