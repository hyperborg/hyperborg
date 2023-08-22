# Generated from speech.pri.

cmake_minimum_required(VERSION 3.16)
project(speech LANGUAGES CXX)

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
find_package(Qt6 COMPONENTS TextToSpeech REQUIRED)

qt_add_library(speech SHARED
    ../../common/common.h
    ../../common/hyobject.h
    ../../common/hyobject.cpp
    ../../common/hyplugin.h
    speech.cpp speech.h
)
target_link_libraries(speech PUBLIC
    Qt::Core
    Qt::Network
    Qt::TextToSpeech
)

install(TARGETS speech
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
