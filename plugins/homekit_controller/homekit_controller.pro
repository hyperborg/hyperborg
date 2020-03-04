include(homekit_controller.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = homekit_controller.h

SOURCES = homekit_controller.cpp

TARGET = $$qtLibraryTarget(homekit_controller)

DESTDIR = ../../plugins

EXAMPLE_FILES = homekit_controller.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


