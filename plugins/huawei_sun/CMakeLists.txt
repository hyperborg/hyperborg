# Generated from huawei_sun.pri.

cmake_minimum_required(VERSION 3.16)
project(huawei_sun LANGUAGES CXX)

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

qt_add_library(huawei_sun SHARED
    ../../common/common.h
    ../../common/hyobject.cpp ../../common/hyobject.h
    ../../common/hyplugin.cpp ../../common/hyplugin.h
    huawei_sun.cpp huawei_sun.h
)
target_link_libraries(huawei_sun PUBLIC
    Qt::Core
    Qt::Network
)

install(TARGETS huawei_sun
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
