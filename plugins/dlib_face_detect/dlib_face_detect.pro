include(dlib_face_detect.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = dlib_face_detect.h

SOURCES = dlib_face_detect.cpp

TARGET = $$qtLibraryTarget(dlib_face_detect)

DESTDIR = ../../plugins

EXAMPLE_FILES = dlib_face_detect.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


