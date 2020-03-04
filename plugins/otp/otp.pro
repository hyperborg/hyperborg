include(otp.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = otp.h

SOURCES = otp.cpp

TARGET = $$qtLibraryTarget(otp)

DESTDIR = ../../plugins

EXAMPLE_FILES = otp.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


