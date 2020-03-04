include(alexa.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = alexa.h

SOURCES = alexa.cpp

TARGET = $$qtLibraryTarget(alexa)

DESTDIR = ../../plugins

EXAMPLE_FILES = alexa.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


