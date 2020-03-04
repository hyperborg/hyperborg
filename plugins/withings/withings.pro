include(withings.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = withings.h

SOURCES = withings.cpp

TARGET = $$qtLibraryTarget(withings)

DESTDIR = ../../plugins

EXAMPLE_FILES = withings.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


