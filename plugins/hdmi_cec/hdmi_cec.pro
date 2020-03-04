include(hdmi_cec.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = hdmi_cec.h

SOURCES = hdmi_cec.cpp

TARGET = $$qtLibraryTarget(hdmi_cec)

DESTDIR = ../../plugins

EXAMPLE_FILES = hdmi_cec.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


