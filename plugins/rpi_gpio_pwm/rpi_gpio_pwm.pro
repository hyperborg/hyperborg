include(rpi_gpio_pwm.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = rpi_gpio_pwm.h

SOURCES = rpi_gpio_pwm.cpp

TARGET = $$qtLibraryTarget(rpi_gpio_pwm)

DESTDIR = ../../plugins

EXAMPLE_FILES = rpi_gpio_pwm.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


