include(discord.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = discord.h

SOURCES = discord.cpp

TARGET = $$qtLibraryTarget(discord)

DESTDIR = ../../plugins

EXAMPLE_FILES = discord.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


