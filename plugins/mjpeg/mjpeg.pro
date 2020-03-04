include(mjpeg.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mjpeg.h

SOURCES = mjpeg.cpp

TARGET = $$qtLibraryTarget(mjpeg)

DESTDIR = ../../plugins

EXAMPLE_FILES = mjpeg.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


