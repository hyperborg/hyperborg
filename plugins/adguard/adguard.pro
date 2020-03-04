include(adguard.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = adguard.h

SOURCES = adguard.cpp

TARGET = $$qtLibraryTarget(adguard)

DESTDIR = ../../plugins

EXAMPLE_FILES = adguard.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


