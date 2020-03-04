include(apprise.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = apprise.h

SOURCES = apprise.cpp

TARGET = $$qtLibraryTarget(apprise)

DESTDIR = ../../plugins

EXAMPLE_FILES = apprise.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


