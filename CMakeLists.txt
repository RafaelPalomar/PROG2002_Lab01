cmake_minimum_required(VERSION 3.15)

project(Lab01)

find_package(OpenGL REQUIRED)

add_subdirectory(glad)
add_subdirectory(glfw)

add_executable(lab01 main.cpp)
target_link_libraries(lab01 glfw glad OpenGL::GL ${CMAKE_DL_LIBS})
