include(logi_circle.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = logi_circle.h

SOURCES = logi_circle.cpp

TARGET = $$qtLibraryTarget(logi_circle)

DESTDIR = ../../plugins

EXAMPLE_FILES = logi_circle.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


