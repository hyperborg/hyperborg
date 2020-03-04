include(nsw_rural_fire_service_feed.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = nsw_rural_fire_service_feed.h

SOURCES = nsw_rural_fire_service_feed.cpp

TARGET = $$qtLibraryTarget(nsw_rural_fire_service_feed)

DESTDIR = ../../plugins

EXAMPLE_FILES = nsw_rural_fire_service_feed.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


