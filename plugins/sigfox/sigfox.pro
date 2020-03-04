include(sigfox.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sigfox.h

SOURCES = sigfox.cpp

TARGET = $$qtLibraryTarget(sigfox)

DESTDIR = ../../plugins

EXAMPLE_FILES = sigfox.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


