include(pjlink.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = pjlink.h

SOURCES = pjlink.cpp

TARGET = $$qtLibraryTarget(pjlink)

DESTDIR = ../../plugins

EXAMPLE_FILES = pjlink.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


