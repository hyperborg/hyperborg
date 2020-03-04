include(msteams.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = msteams.h

SOURCES = msteams.cpp

TARGET = $$qtLibraryTarget(msteams)

DESTDIR = ../../plugins

EXAMPLE_FILES = msteams.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


