cmake_minimum_required(VERSION 3.17)
project(raytest)

set(CMAKE_CXX_STANDARD 20)

# Add sources
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "src/*.hpp")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Setup raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(deps/raylib)
target_link_libraries(${PROJECT_NAME}
        PRIVATE raylib)
