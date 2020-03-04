include(volkszaehler.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = volkszaehler.h

SOURCES = volkszaehler.cpp

TARGET = $$qtLibraryTarget(volkszaehler)

DESTDIR = ../../plugins

EXAMPLE_FILES = volkszaehler.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


