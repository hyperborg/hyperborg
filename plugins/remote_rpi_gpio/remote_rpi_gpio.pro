include(remote_rpi_gpio.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = remote_rpi_gpio.h

SOURCES = remote_rpi_gpio.cpp

TARGET = $$qtLibraryTarget(remote_rpi_gpio)

DESTDIR = ../../plugins

EXAMPLE_FILES = remote_rpi_gpio.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


