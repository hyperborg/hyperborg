include(local_ip.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = local_ip.h

SOURCES = local_ip.cpp

TARGET = $$qtLibraryTarget(local_ip)

DESTDIR = ../../plugins

EXAMPLE_FILES = local_ip.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


