include(huawei_router.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = huawei_router.h

SOURCES = huawei_router.cpp

TARGET = $$qtLibraryTarget(huawei_router)

DESTDIR = ../../plugins

EXAMPLE_FILES = huawei_router.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


