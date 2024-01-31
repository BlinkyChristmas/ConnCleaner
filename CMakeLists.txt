cmake_minimjum_required(VERSION 3.25)
project(ConnCleaner VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(ConnCleaner

    ${PROJECT_SOURCE_DIR}/ConnCleaner/main.cpp
    
    ${PROJECT_SOURCE_DIR}/ConnCleaner/ConnectionStatus.cpp
    ${PROJECT_SOURCE_DIR}/ConnCleaner/ConnectionStatus.hpp
    ${PROJECT_SOURCE_DIR}/ConnCleaner/LogContainer.cpp
    ${PROJECT_SOURCE_DIR}/ConnCleaner/LogContainer.hpp
    ${PROJECT_SOURCE_DIR}/ConnCleaner/LogEntry.cpp
    ${PROJECT_SOURCE_DIR}/ConnCleaner/LogEntry.hpp

    ${PROJECT_SOURCE_DIR}/common/utility/buffer.cpp
    ${PROJECT_SOURCE_DIR}/common/utility/buffer.hpp
    ${PROJECT_SOURCE_DIR}/common/utility/dbgutil.hpp
    ${PROJECT_SOURCE_DIR}/common/utility/mapfile.cpp
    ${PROJECT_SOURCE_DIR}/common/utility/mapfile.hpp
    ${PROJECT_SOURCE_DIR}/common/utility/strutil.hpp
    ${PROJECT_SOURCE_DIR}/common/utility/timeutil.cpp
    ${PROJECT_SOURCE_DIR}/common/utility/timeutil.hpp
)

if (WIN32)
    target_compile_definitions(ConnCleaner PRIVATE
        $<$<CONFIG:Release>:NDEBUG>
        $<$<CONFIG:Debug>:_DEBUG>
        _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
    )
    target_compile_options(ConnCleaner PRIVATE
        $<$<CONFIG:Release>:/O2>
    )
else()
    target_compile_definitions(ConnCleaner PRIVATE
        $<$<CONFIG:Debug>:_DEBUG>
    )

    target_compile_options(ConnCleaner PRIVATE
        $<$<CONFIG:Release>:-O2>
        -Wno-deprecated-declarations
    )
endif (WIN32)

target_include_directories(ConnCleaner
    PUBLIC
        ${PROJECT_SOURCE_DIR}/ConnCleaner/
        ${PROJECT_SOURCE_DIR}/common/
)

    

