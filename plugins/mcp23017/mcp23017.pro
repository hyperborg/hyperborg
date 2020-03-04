include(mcp23017.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mcp23017.h

SOURCES = mcp23017.cpp

TARGET = $$qtLibraryTarget(mcp23017)

DESTDIR = ../../plugins

EXAMPLE_FILES = mcp23017.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


