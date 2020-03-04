include(iperf3.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = iperf3.h

SOURCES = iperf3.cpp

TARGET = $$qtLibraryTarget(iperf3)

DESTDIR = ../../plugins

EXAMPLE_FILES = iperf3.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


