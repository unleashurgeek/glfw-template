cmake_minimum_required(VERSION 3.0)

project(glad C)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)

    if (NOT USE_MSVC_RUNTIME_LIBRARY_DLL)
        foreach (flag
                    CMAKE_C_FLAGS
                    CMAKE_C_FLAGS_DEBUG
                    CMAKE_C_FLAGS_RELEASE
                    CMAKE_C_FLAGS_MINSIZEREL
                    CMAKE_C_FLAGS_RELWITHDEBINFO)
            if (${flag} MATCHES "/MD")
                string(REGEX REPLACE "/MD" "/MT" ${flag} "${${flag}}")
            endif()
            if (${flag} MATCHES "/MDd")
                string(REGEX REPLACE "/MDd" "/MTd" ${flag} "${${flag}}")
            endif()
        endforeach()
    endif()
endif()

include_directories(include)
add_library(glad src/glad.c include/glad/glad.h include/KHR/khrplatform.h)

set_target_properties(glad PROPERTIES FOLDER "glad")
