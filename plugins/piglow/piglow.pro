include(piglow.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = piglow.h

SOURCES = piglow.cpp

TARGET = $$qtLibraryTarget(piglow)

DESTDIR = ../../plugins

EXAMPLE_FILES = piglow.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


