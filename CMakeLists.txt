cmake_minimum_required(VERSION 3.10)
project(Hook)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCES "src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/includes)
target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/lib)

target_link_libraries(${PROJECT_NAME} raylib m dl pthread GL X11 Xrandr Xi Xxf86vm Xcursor)
