include(hhc_n8i8op.pri)

QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter
contains(QT_CONFIG, c++11): CONFIG+= c++11

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= network

INCLUDEPATH +=. ../../common
TARGET = $$qtLibraryTarget(hhc_n8i8op)
DESTDIR = ../../plugins
EXAMPLE_FILES = hhc_n8i8op.json

linux {
    MOC_DIR=../../.build/.moc
    OBJECTS_DIR=../../.build/.objs
    RCC_DIR=../../.build/.rcc
    UI_DIR=../../.build/.uic
}

raspberry {
    DEFINES+=PLATFORM_RPI
}
