cmake_minimum_required(VERSION 3.17)
project(raytest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE on)

if(PLATFORM STREQUAL "Web")
  set(PLATFORM Web CACHE STRING "" FORCE)

  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/cmake-build-emscripten)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/cmake-build-emscripten)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/output-web)
  SET(CMAKE_EXECUTABLE_SUFFIX ".html")
endif()

# Add sources
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "src/*.hpp")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

if(PLATFORM STREQUAL "Web")
  set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS
          "-s USE_GLFW=3 -s ASYNCIFY -s WASM=1 -s ASSERTIONS=1 -s DEMANGLE_SUPPORT=1 --bind \
          --shell-file ${CMAKE_CURRENT_SOURCE_DIR}/emscripten_shell.html \
          --preload-file ${CMAKE_CURRENT_SOURCE_DIR}/assets")
endif()

# Setup raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(STATIC ON CACHE BOOL "" FORCE)
add_subdirectory(deps/raylib)
target_link_libraries(${PROJECT_NAME}
        PRIVATE raylib_static)
