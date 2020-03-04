include(zabbix.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = zabbix.h

SOURCES = zabbix.cpp

TARGET = $$qtLibraryTarget(zabbix)

DESTDIR = ../../plugins

EXAMPLE_FILES = zabbix.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


