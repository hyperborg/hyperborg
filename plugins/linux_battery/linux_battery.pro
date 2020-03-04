include(linux_battery.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = linux_battery.h

SOURCES = linux_battery.cpp

TARGET = $$qtLibraryTarget(linux_battery)

DESTDIR = ../../plugins

EXAMPLE_FILES = linux_battery.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


