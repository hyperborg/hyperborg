include(pocketcasts.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = pocketcasts.h

SOURCES = pocketcasts.cpp

TARGET = $$qtLibraryTarget(pocketcasts)

DESTDIR = ../../plugins

EXAMPLE_FILES = pocketcasts.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


