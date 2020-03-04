include(foobot.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = foobot.h

SOURCES = foobot.cpp

TARGET = $$qtLibraryTarget(foobot)

DESTDIR = ../../plugins

EXAMPLE_FILES = foobot.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


