include(sighthound.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sighthound.h

SOURCES = sighthound.cpp

TARGET = $$qtLibraryTarget(sighthound)

DESTDIR = ../../plugins

EXAMPLE_FILES = sighthound.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


