include(minecraft_server.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = minecraft_server.h

SOURCES = minecraft_server.cpp

TARGET = $$qtLibraryTarget(minecraft_server)

DESTDIR = ../../plugins

EXAMPLE_FILES = minecraft_server.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


