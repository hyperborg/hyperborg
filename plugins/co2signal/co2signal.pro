include(co2signal.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = co2signal.h

SOURCES = co2signal.cpp

TARGET = $$qtLibraryTarget(co2signal)

DESTDIR = ../../plugins

EXAMPLE_FILES = co2signal.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


