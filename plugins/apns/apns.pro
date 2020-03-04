include(apns.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = apns.h

SOURCES = apns.cpp

TARGET = $$qtLibraryTarget(apns)

DESTDIR = ../../plugins

EXAMPLE_FILES = apns.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


