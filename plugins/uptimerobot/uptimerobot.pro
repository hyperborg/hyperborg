include(uptimerobot.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = uptimerobot.h

SOURCES = uptimerobot.cpp

TARGET = $$qtLibraryTarget(uptimerobot)

DESTDIR = ../../plugins

EXAMPLE_FILES = uptimerobot.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


