include(orangepi_gpio.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = orangepi_gpio.h

SOURCES = orangepi_gpio.cpp

TARGET = $$qtLibraryTarget(orangepi_gpio)

DESTDIR = ../../plugins

EXAMPLE_FILES = orangepi_gpio.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


