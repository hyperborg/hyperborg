include(twitch.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = twitch.h

SOURCES = twitch.cpp

TARGET = $$qtLibraryTarget(twitch)

DESTDIR = ../../plugins

EXAMPLE_FILES = twitch.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


