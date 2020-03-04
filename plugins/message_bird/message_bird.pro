include(message_bird.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = message_bird.h

SOURCES = message_bird.cpp

TARGET = $$qtLibraryTarget(message_bird)

DESTDIR = ../../plugins

EXAMPLE_FILES = message_bird.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


