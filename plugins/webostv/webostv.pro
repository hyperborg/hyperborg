include(webostv.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = webostv.h

SOURCES = webostv.cpp

TARGET = $$qtLibraryTarget(webostv)

DESTDIR = ../../plugins

EXAMPLE_FILES = webostv.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


