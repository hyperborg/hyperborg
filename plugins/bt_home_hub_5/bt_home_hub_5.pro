include(bt_home_hub_5.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = bt_home_hub_5.h

SOURCES = bt_home_hub_5.cpp

TARGET = $$qtLibraryTarget(bt_home_hub_5)

DESTDIR = ../../plugins

EXAMPLE_FILES = bt_home_hub_5.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


