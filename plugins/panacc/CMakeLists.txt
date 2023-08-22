# Generated from panacc.pri.

cmake_minimum_required(VERSION 3.16)
project(panacc LANGUAGES CXX)

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

qt_add_library(panacc SHARED
    ../../common/common.h
    ../../common/hyobject.h
    ../../common/hyobject.cpp
    ../../common/hyplugin.h
    panacc.cpp panacc.h
)
target_link_libraries(panacc PUBLIC
    Qt::Core
    Qt::Network
)

install(TARGETS panacc
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
