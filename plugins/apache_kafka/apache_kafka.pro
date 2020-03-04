include(apache_kafka.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = apache_kafka.h

SOURCES = apache_kafka.cpp

TARGET = $$qtLibraryTarget(apache_kafka)

DESTDIR = ../../plugins

EXAMPLE_FILES = apache_kafka.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


