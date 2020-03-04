include(openalpr_cloud.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = openalpr_cloud.h

SOURCES = openalpr_cloud.cpp

TARGET = $$qtLibraryTarget(openalpr_cloud)

DESTDIR = ../../plugins

EXAMPLE_FILES = openalpr_cloud.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


