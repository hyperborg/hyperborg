cmake_minimum_required(VERSION 3.16)
project(calendar LANGUAGES CXX)

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

qt_add_library(calendar SHARED
    ../../common/common.h
    ../../common/hyplugin_interface.h
    ../../common/hplugin.h ../../common/hplugin.cpp
    calendar.h calendar.cpp
)
target_link_libraries(calendar PUBLIC
    Qt::Core
)

install(TARGETS calendar
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
