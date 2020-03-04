include(ffmpeg_motion.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ffmpeg_motion.h

SOURCES = ffmpeg_motion.cpp

TARGET = $$qtLibraryTarget(ffmpeg_motion)

DESTDIR = ../../plugins

EXAMPLE_FILES = ffmpeg_motion.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


