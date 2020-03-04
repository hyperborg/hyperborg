include(hisense_aehw4a1.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = hisense_aehw4a1.h

SOURCES = hisense_aehw4a1.cpp

TARGET = $$qtLibraryTarget(hisense_aehw4a1)

DESTDIR = ../../plugins

EXAMPLE_FILES = hisense_aehw4a1.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


