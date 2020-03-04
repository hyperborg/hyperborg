include(pulseaudio_loopback.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = pulseaudio_loopback.h

SOURCES = pulseaudio_loopback.cpp

TARGET = $$qtLibraryTarget(pulseaudio_loopback)

DESTDIR = ../../plugins

EXAMPLE_FILES = pulseaudio_loopback.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


