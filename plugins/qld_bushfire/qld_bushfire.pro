include(qld_bushfire.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = qld_bushfire.h

SOURCES = qld_bushfire.cpp

TARGET = $$qtLibraryTarget(qld_bushfire)

DESTDIR = ../../plugins

EXAMPLE_FILES = qld_bushfire.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


