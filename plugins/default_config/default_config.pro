include(default_config.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = default_config.h

SOURCES = default_config.cpp

TARGET = $$qtLibraryTarget(default_config)

DESTDIR = ../../plugins

EXAMPLE_FILES = default_config.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


