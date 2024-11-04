cmake_minimum_required(VERSION 3.16)
project(hb_i2c LANGUAGES CXX)

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
find_library(i2c_LIB i2c)

qt_add_library(hb_i2c SHARED
    ../../common/common.h
    ../../common/hyplugin_interface.h
    ../../common/hplugin.h  ../../common/hplugin.cpp
    hb_i2c.cpp hb_i2c.h
)

target_link_libraries(hb_i2c PUBLIC
    i2c
    Qt::Core
    Qt::Network
)

install(TARGETS hb_i2c
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
