include(homematicip_cloud.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = homematicip_cloud.h

SOURCES = homematicip_cloud.cpp

TARGET = $$qtLibraryTarget(homematicip_cloud)

DESTDIR = ../../plugins

EXAMPLE_FILES = homematicip_cloud.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


