include(rpi_camera.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = rpi_camera.h

SOURCES = rpi_camera.cpp

TARGET = $$qtLibraryTarget(rpi_camera)

DESTDIR = ../../plugins

EXAMPLE_FILES = rpi_camera.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


