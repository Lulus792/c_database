cmake_minimum_required(VERSION 3.0)

project(Database VERSION 1.0 LANGUAGES C)

set(CMAKE_C_COMPILER "/usr/bin/gcc-13")
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

if (CMAKE_C_COMPILER)
  add_compile_options(
    -Wall
    -Wextra
    -Werror
    -Wpedantic
    -pedantic
    -pedantic-errors
  )
endif()

find_package(raylib)

if (NOT raylib_FOUND)
  message(FATAL_ERROR "Raylib not found")
endif()

set(SOURCES
  src/main.c
)

set(HEADERS
  
)

add_executable(Database ${SOURCES} ${HEADERS})

target_link_libraries(Database PRIVATE raylib)
