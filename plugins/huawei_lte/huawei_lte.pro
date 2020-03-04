include(huawei_lte.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = huawei_lte.h

SOURCES = huawei_lte.cpp

TARGET = $$qtLibraryTarget(huawei_lte)

DESTDIR = ../../plugins

EXAMPLE_FILES = huawei_lte.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


