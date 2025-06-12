cmake_minimum_required(VERSION 3.10)

# VCPKG Integration (automatisch, wenn Umgebungsvariable gesetzt ist)
set(CMAKE_TOOLCHAIN_FILE "C:/Users/User/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

project(NanaProjekt)

set(CMAKE_CXX_STANDARD 17)

find_package(nana CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(NanaProjekt Process_input.cpp)

target_link_libraries(NanaProjekt PRIVATE nana::nana OpenGL::GL OpenGL::GLU)