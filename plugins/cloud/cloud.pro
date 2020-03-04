include(cloud.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = cloud.h

SOURCES = cloud.cpp

TARGET = $$qtLibraryTarget(cloud)

DESTDIR = ../../plugins

EXAMPLE_FILES = cloud.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


