QT += core network xml gui widgets websockets charts

TEMPLATE=app
TARGET=../hynode
CONFIG+= release warn_off
CONFIG-= tooltip app_bundle

QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter

contains(QT_CONFIG, c++11): CONFIG+= c++11

DEPENDPATH += .
INCLUDEPATH += . ../common

emscripten {
    MOC_DIR= ../.build_wasm/.moc
    OBJECTS_DIR= ../.build_wasm/.objs
    RCC_DIR= ../.build_wasm/.rcc
    UI_DIR= ../.build_wasm/.uic
    DESTDIR=.
    INCLUDEPATH+=/usr/local/QT5WASM/include
    INCLUDEPATH += /usr/local/QT5_WASM/include /usr/local/QT5_WASM/include/QtGui /usr/local/QT5_WASM/include/QtWidgets /usr/local/fontconfig
    DEFINES+=WASM WEBASSEMBLY
}

linux {
    MOC_DIR= ../.build/.moc
    OBJECTS_DIR= ../.build/.objs
    RCC_DIR= ../.build/.rcc
    UI_DIR= ../.build/.uic
    DESTDIR=.
    INCLUDEPATH+=
    DEFINES+=LINUX
}

include(node.pri)

