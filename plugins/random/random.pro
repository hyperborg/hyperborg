include(random.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = random.h

SOURCES = random.cpp

TARGET = $$qtLibraryTarget(random)

DESTDIR = ../../plugins

EXAMPLE_FILES = random.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


