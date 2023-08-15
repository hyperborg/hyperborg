include(paradox.pri)

TEMPLATE=lib
CONFIG+=plugin
QT+= xml serialport

INCLUDEPATH +=../../common
HEADER = paradox.h
SOURCES = paradox.cpp
TARGET = $$qtLibraryTarget(paradox)
DESTDIR = ../../plugins
EXAMPLE_FILES = paradox.json

MOC_DIR=../../.build/.moc/$$TARGET
OBJECTS_DIR=../../.build/.objs/$$TARGET
RCC_DIR=../../.build/.rcc/$$TARGET
UI_DIR=../../.build/.uic/$$TARGET


