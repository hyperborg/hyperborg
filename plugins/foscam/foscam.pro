include(foscam.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = foscam.h

SOURCES = foscam.cpp

TARGET = $$qtLibraryTarget(foscam)

DESTDIR = ../../plugins

EXAMPLE_FILES = foscam.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


