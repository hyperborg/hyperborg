include(tank_utility.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tank_utility.h

SOURCES = tank_utility.cpp

TARGET = $$qtLibraryTarget(tank_utility)

DESTDIR = ../../plugins

EXAMPLE_FILES = tank_utility.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


