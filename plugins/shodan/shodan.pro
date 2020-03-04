include(shodan.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = shodan.h

SOURCES = shodan.cpp

TARGET = $$qtLibraryTarget(shodan)

DESTDIR = ../../plugins

EXAMPLE_FILES = shodan.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


