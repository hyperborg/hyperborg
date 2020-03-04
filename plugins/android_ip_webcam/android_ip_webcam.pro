include(android_ip_webcam.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = android_ip_webcam.h

SOURCES = android_ip_webcam.cpp

TARGET = $$qtLibraryTarget(android_ip_webcam)

DESTDIR = ../../plugins

EXAMPLE_FILES = android_ip_webcam.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


