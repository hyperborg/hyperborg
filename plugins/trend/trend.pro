include(trend.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = trend.h

SOURCES = trend.cpp

TARGET = $$qtLibraryTarget(trend)

DESTDIR = ../../plugins

EXAMPLE_FILES = trend.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


