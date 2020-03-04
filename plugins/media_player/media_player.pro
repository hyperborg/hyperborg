include(media_player.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = media_player.h

SOURCES = media_player.cpp

TARGET = $$qtLibraryTarget(media_player)

DESTDIR = ../../plugins

EXAMPLE_FILES = media_player.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


