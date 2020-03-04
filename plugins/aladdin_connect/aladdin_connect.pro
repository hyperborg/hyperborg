include(aladdin_connect.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = aladdin_connect.h

SOURCES = aladdin_connect.cpp

TARGET = $$qtLibraryTarget(aladdin_connect)

DESTDIR = ../../plugins

EXAMPLE_FILES = aladdin_connect.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


