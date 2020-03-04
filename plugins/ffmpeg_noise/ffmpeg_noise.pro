include(ffmpeg_noise.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ffmpeg_noise.h

SOURCES = ffmpeg_noise.cpp

TARGET = $$qtLibraryTarget(ffmpeg_noise)

DESTDIR = ../../plugins

EXAMPLE_FILES = ffmpeg_noise.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


