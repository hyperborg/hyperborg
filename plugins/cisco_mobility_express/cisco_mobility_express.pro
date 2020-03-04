include(cisco_mobility_express.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = cisco_mobility_express.h

SOURCES = cisco_mobility_express.cpp

TARGET = $$qtLibraryTarget(cisco_mobility_express)

DESTDIR = ../../plugins

EXAMPLE_FILES = cisco_mobility_express.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


