include(islamic_prayer_times.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = islamic_prayer_times.h

SOURCES = islamic_prayer_times.cpp

TARGET = $$qtLibraryTarget(islamic_prayer_times)

DESTDIR = ../../plugins

EXAMPLE_FILES = islamic_prayer_times.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


