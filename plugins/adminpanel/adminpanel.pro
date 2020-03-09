include(adminpanel.pri)
QT += core network xml gui widgets websockets
contains(QT_CONFIG, c++11): CONFIG+= c++11

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml
INCLUDEPATH +=. ../../common
CONFIG+= release warn_off
CONFIG-= tooltip app_bundle

TARGET = $$qtLibraryTarget(adminpanel)

DESTDIR = ../../plugins
EXAMPLE_FILES = adminpanel.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic

emscripten {
    MOC_DIR= ../../.build_wasm/.moc
    OBJECTS_DIR= ../../.build_wasm/.objs
    RCC_DIR= ../../.build_wasm/.rcc
    UI_DIR= ../../.build_wasm/.uic
    DESTDIR=..
    INCLUDEPATH+=/usr/local/QT5WASM/include
    INCLUDEPATH += /usr/local/QT5_WASM/include /usr/local/QT5_WASM/include/QtGui /usr/local/QT5_WASM/include/QtWidgets /usr/local/fontconfig
    DEFINES+=WASM WEBASSEMBLY
}

linux {
    MOC_DIR= ../../.build/.moc
    OBJECTS_DIR= ../../.build/.objs
    RCC_DIR= ../../.build/.rcc
    UI_DIR= ../../.build/.uic
    DESTDIR=..
    INCLUDEPATH+=
    DEFINES+=LINUX
}

