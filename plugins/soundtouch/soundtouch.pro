include(soundtouch.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = soundtouch.h

SOURCES = soundtouch.cpp

TARGET = $$qtLibraryTarget(soundtouch)

DESTDIR = ../../plugins

EXAMPLE_FILES = soundtouch.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


