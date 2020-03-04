include(clicksend.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = clicksend.h

SOURCES = clicksend.cpp

TARGET = $$qtLibraryTarget(clicksend)

DESTDIR = ../../plugins

EXAMPLE_FILES = clicksend.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


