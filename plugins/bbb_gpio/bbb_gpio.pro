include(bbb_gpio.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = bbb_gpio.h

SOURCES = bbb_gpio.cpp

TARGET = $$qtLibraryTarget(bbb_gpio)

DESTDIR = ../../plugins

EXAMPLE_FILES = bbb_gpio.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


