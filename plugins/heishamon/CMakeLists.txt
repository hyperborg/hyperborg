# Generated from heishamon.pri.

cmake_minimum_required(VERSION 3.16)
project(heishamon LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

INCLUDE_DIRECTORIES(../../common)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
  set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}")

find_package(Qt6 COMPONENTS Core REQUIRED)
find_package(Qt6 COMPONENTS Network REQUIRED)
find_package(Qt6 COMPONENTS Mqtt REQUIRED)

qt_add_library(heishamon SHARED
    ../../common/common.h
    ../../common/hyplugin_interface.h
    ../../common/hplugin.h
    ../../common/hplugin.cpp
    heishamon.cpp heishamon.h
)
target_link_libraries(heishamon PUBLIC
    Qt::Core
    Qt::Network
    Qt::Mqtt
)

install(TARGETS heishamon
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
