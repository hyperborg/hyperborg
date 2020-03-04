include(bt_smarthub.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = bt_smarthub.h

SOURCES = bt_smarthub.cpp

TARGET = $$qtLibraryTarget(bt_smarthub)

DESTDIR = ../../plugins

EXAMPLE_FILES = bt_smarthub.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


