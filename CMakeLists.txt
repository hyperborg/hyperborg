cmake_minimum_required(VERSION 3.22)
project(hyperborg)
add_subdirectory(node)

if (CMAKE_CXX_PLATFORM_ID STREQUAL "Linux")
    add_compile_definitions(PF_LINUX)
    add_compile_definitions(Q_COMPILER_INITIALIZER_LISTS)

    add_subdirectory(plugins/backup)
    add_subdirectory(plugins/hb_i2c)
    add_subdirectory(plugins/backupserver)
    add_subdirectory(plugins/calendar)
    add_subdirectory(plugins/heishamon)
    add_subdirectory(plugins/hhc_n8i8op)
    add_subdirectory(plugins/huawei_sun)
    add_subdirectory(plugins/hue)
    add_subdirectory(plugins/jmeter)
    add_subdirectory(plugins/medialibrary)
    add_subdirectory(plugins/mqtt)
    add_subdirectory(plugins/onewire)
    add_subdirectory(plugins/panacc)
    add_subdirectory(plugins/paradox)
    add_subdirectory(plugins/speech)
    add_subdirectory(plugins/system)
    add_subdirectory(plugins/ws3500)
    add_subdirectory(plugins/bme688)
    add_subdirectory(plugins/bme688_bsec)


endif()

if (CMAKE_CXX_PLATFORM_ID STREQUAL "emscripten")
    add_compile_definitions(PF_EMSCRIPTEN)
    add_compile_definitions(WASM)
    add_compile_definitions(Q_COMPILER_INITIALIZER_LISTS)
endif()


