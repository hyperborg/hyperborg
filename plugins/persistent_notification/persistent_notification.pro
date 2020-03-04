include(persistent_notification.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = persistent_notification.h

SOURCES = persistent_notification.cpp

TARGET = $$qtLibraryTarget(persistent_notification)

DESTDIR = ../../plugins

EXAMPLE_FILES = persistent_notification.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


