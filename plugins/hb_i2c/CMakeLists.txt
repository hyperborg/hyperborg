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

qt_add_library(hb_i2c SHARED
    ../../common/common.h
    ../../common/hyobject.h
    ../../common/hyobject.cpp
    ../../common/hyplugin.h
    hb_i2c.cpp hb_i2c.h
)

target_link_libraries(hb_i2c PUBLIC
    Qt::Core
    Qt::Network
)

install(TARGETS hb_i2c
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
