cmake_minimum_required(VERSION 3.16)
project(GL_P1)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)

include_directories(include)
link_directories(lib)

add_executable(${PROJECT_NAME} main.cpp glad.c src/Shader.h include/stb_image.h include/stb_image.cpp src/Image.h)

target_link_libraries(${PROJECT_NAME} libglfw3.a)