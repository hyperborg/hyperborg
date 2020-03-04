include(nederlandse_spoorwegen.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = nederlandse_spoorwegen.h

SOURCES = nederlandse_spoorwegen.cpp

TARGET = $$qtLibraryTarget(nederlandse_spoorwegen)

DESTDIR = ../../plugins

EXAMPLE_FILES = nederlandse_spoorwegen.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


