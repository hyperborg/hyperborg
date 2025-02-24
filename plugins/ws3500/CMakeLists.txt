# Generated from ws3500.pri.

cmake_minimum_required(VERSION 3.16)
project(ws3500 LANGUAGES CXX)

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

qt_add_library(ws3500 SHARED
    ../../common/common.h
    ../../common/hyplugin_interface.h ../../common/hyplugin_interface.cpp
    ../../common/hplugin.h ../../common/hplugin.cpp
    ../../common/hdevice.h ../../common/hdevice.cpp
    ../../common/hdevice.h ../../common/hdevice.cpp
    ../../common/hactor.h ../../common/hactor.cpp
    ../../common/hsensor.h ../../common/hsensor.cpp
    ws3500.cpp ws3500.h
    ws3500_device.cpp ws3500_device.h
)
target_link_libraries(ws3500 PUBLIC
    Qt::Core
    Qt::Network
)

install(TARGETS ws3500
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
