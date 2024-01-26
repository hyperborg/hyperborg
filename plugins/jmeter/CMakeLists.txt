cmake_minimum_required(VERSION 3.16)
project(jmeter LANGUAGES CXX)

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

qt_add_library(jmeter SHARED
    ../../common/common.h
    ../../common/hyobject.h
    ../../common/hyobject.cpp
    ../../common/hyplugin.h
    jmeter.cpp jmeter.h
)

target_link_libraries(jmeter PUBLIC
    Qt::Core
    Qt::Network
    Qt::Sql
)

install(TARGETS jmeter
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
