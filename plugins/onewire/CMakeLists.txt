# Generated from onewire.pri.

cmake_minimum_required(VERSION 3.16)
project(onewire LANGUAGES CXX)

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

qt_add_library(onewire SHARED
    ../../common/common.h
    ../../common/hyplugin_interface.h ../../common/hyplugin_interface.cpp
    ../../common/hplugin.h ../../common/hplugin.cpp
    onewire.cpp onewire.h
)
target_link_libraries(onewire PUBLIC
    Qt::Core
)

install(TARGETS onewire
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
