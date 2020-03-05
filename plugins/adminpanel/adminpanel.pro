include(adminpanel.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = adminpanel.h

SOURCES = adminpanel.cpp

TARGET = $$qtLibraryTarget(adminpanel)

DESTDIR = ../../plugins

EXAMPLE_FILES = adminpanel.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


