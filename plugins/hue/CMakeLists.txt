# Generated from hue.pri.

cmake_minimum_required(VERSION 3.16)
project(hue LANGUAGES CXX)

INCLUDE_DIRECTORIES(../../common)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
  set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}")

find_package(Qt6 COMPONENTS Core REQUIRED)
find_package(Qt6 COMPONENTS Network REQUIRED)

qt_add_library(hue SHARED
    ../../common/common.h
    ../../common/hdevice.cpp ../../common/hdevice.h
    ../../common/hyobject.cpp ../../common/hyobject.h
    ../../common/hyplugin.cpp ../../common/hyplugin.h
    hue.cpp hue.h
    hue_device.cpp hue_device.h
)
target_link_libraries(hue PUBLIC
    Qt::Core
    Qt::Network
)

install(TARGETS hue
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
