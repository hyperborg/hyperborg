#-------------------------------------------------
#
# Project created by QtCreator 2011-12-11T15:38:42
#
#-------------------------------------------------

QT += core network xml

TEMPLATE=app
TARGET=hynode
CONFIG+= release warn_off
CONFIG-= tooltip

contains(QT_CONFIG, c++11): CONFIG+= c++11

DEPENDPATH += .
INCLUDEPATH += . \
	    ../common \
	    ../hycore

emscripten
{
    DESTDIR=.
    MOC_DIR=.moc
    UI_DIR=.ui
    RCC_DIR=.rcc
    OBJECTS_DIR=.objs
#   INCLUDEPATH+=
#   DEFINES+=
}

linux
{
    DESTDIR=.
    MOC_DIR=.moc
    UI_DIR=.ui
    RCC_DIR=.rcc
    OBJECTS_DIR=.objs
#   INCLUDEPATH+=
#   DEFINES+=
}

include(hynode.pri)