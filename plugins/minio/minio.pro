include(minio.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = minio.h

SOURCES = minio.cpp

TARGET = $$qtLibraryTarget(minio)

DESTDIR = ../../plugins

EXAMPLE_FILES = minio.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


