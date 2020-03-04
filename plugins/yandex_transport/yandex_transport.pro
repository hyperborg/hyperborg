include(yandex_transport.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = yandex_transport.h

SOURCES = yandex_transport.cpp

TARGET = $$qtLibraryTarget(yandex_transport)

DESTDIR = ../../plugins

EXAMPLE_FILES = yandex_transport.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


