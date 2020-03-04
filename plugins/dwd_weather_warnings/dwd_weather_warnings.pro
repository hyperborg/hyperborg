include(dwd_weather_warnings.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = dwd_weather_warnings.h

SOURCES = dwd_weather_warnings.cpp

TARGET = $$qtLibraryTarget(dwd_weather_warnings)

DESTDIR = ../../plugins

EXAMPLE_FILES = dwd_weather_warnings.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


