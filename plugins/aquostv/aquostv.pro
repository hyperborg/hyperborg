include(aquostv.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = aquostv.h

SOURCES = aquostv.cpp

TARGET = $$qtLibraryTarget(aquostv)

DESTDIR = ../../plugins

EXAMPLE_FILES = aquostv.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


