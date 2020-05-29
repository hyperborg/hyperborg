include(node.pri)
QT += core network xml gui widgets websockets charts qml

TEMPLATE=app
TARGET=../hynode
CONFIG+= release warn_off
CONFIG-= tooltip app_bundle

QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter

#Limit memory usage, so it could start on machines with 2GB RAM
QMAKE_WASM_TOTAL_MEMORY=256MB

contains(QT_CONFIG, c++11): CONFIG+= c++11

DEPENDPATH += .
INCLUDEPATH += . ../common

linux {
    DEFINES+=LINUX
    MOC_DIR= ../.build/.moc
    OBJECTS_DIR= ../.build/.objs
    RCC_DIR= ../.build/.rcc
    UI_DIR= ../.build/.uic
    DESTDIR=.
    INCLUDEPATH+=
}

emscripten {
    DEFINES+=WASM WEBASSEMBLY
    MOC_DIR= ../.build_wasm/.moc
    OBJECTS_DIR= ../.build_wasm/.objs
    RCC_DIR= ../.build_wasm/.rcc
    UI_DIR= ../.build_wasm/.uic
    DESTDIR=.
    INCLUDEPATH+=/usr/local/QT5WASM/include
#    INCLUDEPATH += /usr/local/QT5_WASM/include /usr/local/QT5_WASM/include/QtGui /usr/local/QT5_WASM/include/QtWidgets /usr/local/fontconfig

# For WASM, all used plugins should be explicitly listed here
    INCLUDEPATH+=../plugins/adminpanel
}





