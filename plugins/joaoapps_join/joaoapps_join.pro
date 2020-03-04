include(joaoapps_join.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = joaoapps_join.h

SOURCES = joaoapps_join.cpp

TARGET = $$qtLibraryTarget(joaoapps_join)

DESTDIR = ../../plugins

EXAMPLE_FILES = joaoapps_join.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


