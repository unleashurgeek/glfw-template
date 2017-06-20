include_directories(${GLFW_SOURCE_DIR}/include)
include_directories(${glad_SOURCE_DIR}/include)

set(gltest_HEADERS game.h)
set(gltest_SOURCES main.cpp game.cpp)

add_executable(gltest ${gltest_SOURCES} ${gltest_HEADERS})
target_link_libraries(gltest glfw glad)

if (MSVC)
  if (NO_CONSOLE)
    set_target_properties(gltest PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
  else()
    set_target_properties(gltest PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE /ENTRY:mainCRTStartup")
  endif()
endif()

install(TARGETS gltest DESTINATION ${CMAKE_SOURCE_DIR}/build/bin)