include(websocket_api.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = websocket_api.h

SOURCES = websocket_api.cpp

TARGET = $$qtLibraryTarget(websocket_api)

DESTDIR = ../../plugins

EXAMPLE_FILES = websocket_api.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


