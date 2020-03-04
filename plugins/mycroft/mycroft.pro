include(mycroft.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mycroft.h

SOURCES = mycroft.cpp

TARGET = $$qtLibraryTarget(mycroft)

DESTDIR = ../../plugins

EXAMPLE_FILES = mycroft.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


