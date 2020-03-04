include(anel_pwrctrl.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = anel_pwrctrl.h

SOURCES = anel_pwrctrl.cpp

TARGET = $$qtLibraryTarget(anel_pwrctrl)

DESTDIR = ../../plugins

EXAMPLE_FILES = anel_pwrctrl.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


