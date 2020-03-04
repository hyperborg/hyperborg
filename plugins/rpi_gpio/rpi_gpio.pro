include(rpi_gpio.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = rpi_gpio.h

SOURCES = rpi_gpio.cpp

TARGET = $$qtLibraryTarget(rpi_gpio)

DESTDIR = ../../plugins

EXAMPLE_FILES = rpi_gpio.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


