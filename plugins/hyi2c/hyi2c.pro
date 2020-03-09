include(hyi2c.pri)

QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter
contains(QT_CONFIG, c++11): CONFIG+= c++11

#QMAKE_CFLAGS_ISYSTEM = -I

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+=xml testlib

INCLUDEPATH +=. ../../common 

HEADER = hyi2c.h

SOURCES = hyi2c.cpp

TARGET = $$qtLibraryTarget(hyi2c)

DESTDIR = ../../plugins

EXAMPLE_FILES = hyi2c.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic

