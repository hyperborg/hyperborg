include(hyi2c.pri)

QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter
contains(QT_CONFIG, c++11): CONFIG+= c++11

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+=xml

INCLUDEPATH +=. ../../common
TARGET = $$qtLibraryTarget(hyi2c)
DESTDIR = ../../plugins
EXAMPLE_FILES = hyi2c.json

linux {
    MOC_DIR=../../.build/.moc
    OBJECTS_DIR=../../.build/.objs
    RCC_DIR=../../.build/.rcc
    UI_DIR=../../.build/.uic
}

raspberry {
    DEFINES+=PLATFORM_RPI
}
