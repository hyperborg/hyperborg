include(vlc_telnet.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = vlc_telnet.h

SOURCES = vlc_telnet.cpp

TARGET = $$qtLibraryTarget(vlc_telnet)

DESTDIR = ../../plugins

EXAMPLE_FILES = vlc_telnet.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


