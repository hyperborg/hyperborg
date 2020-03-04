include(sleepiq.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sleepiq.h

SOURCES = sleepiq.cpp

TARGET = $$qtLibraryTarget(sleepiq)

DESTDIR = ../../plugins

EXAMPLE_FILES = sleepiq.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


