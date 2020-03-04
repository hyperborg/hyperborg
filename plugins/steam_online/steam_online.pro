include(steam_online.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = steam_online.h

SOURCES = steam_online.cpp

TARGET = $$qtLibraryTarget(steam_online)

DESTDIR = ../../plugins

EXAMPLE_FILES = steam_online.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


