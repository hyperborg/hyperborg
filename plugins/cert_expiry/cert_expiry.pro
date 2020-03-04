include(cert_expiry.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = cert_expiry.h

SOURCES = cert_expiry.cpp

TARGET = $$qtLibraryTarget(cert_expiry)

DESTDIR = ../../plugins

EXAMPLE_FILES = cert_expiry.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


