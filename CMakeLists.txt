cmake_minimum_required(VERSION 3.22)

project(hyperborg)

add_subdirectory(node)

if (LINUX)
    add_compile_definitions(PF_LINUX)
    add_subdirectory(plugins/onewire)
    add_subdirectory(plugins/hhc_n8i8op)
    add_subdirectory(plugins/paradox)
    add_subdirectory(plugins/hue)
    add_subdirectory(plugins/ws3500)
    add_subdirectory(plugins/panacc)
endif()

if (EMSCRIPTEN)
    add_compile_definitions(PF_EMSCRIPTEN)
endif()


