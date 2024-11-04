cmake_minimum_required(VERSION 3.16)
project(bme688 LANGUAGES CXX)

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

qt_add_library(bme688 SHARED
    ../../common/common.h
    ../../common/hyplugin_interface.h
    ../../common/hplugin.h ../../common/hplugin.cpp
    ../../common/hdevice.h ../../common/hdevice.cpp
    ../../common/hactor.h ../../common/hactor.cpp
    bme688.cpp bme688.h
)

target_link_libraries(bme688 PUBLIC
    Qt::Core
    Qt::Network
)

install(TARGETS bme688
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
