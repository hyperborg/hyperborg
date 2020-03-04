include(xeoma.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = xeoma.h

SOURCES = xeoma.cpp

TARGET = $$qtLibraryTarget(xeoma)

DESTDIR = ../../plugins

EXAMPLE_FILES = xeoma.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


