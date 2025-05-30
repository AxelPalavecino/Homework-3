cmake_minimum_required(VERSION 3.10)
project(Homework-3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Agregar flags de compilación para detectar errores
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic")

add_subdirectory(exercises/ex1_serializacion)
add_subdirectory(exercises/ex2_templates)
add_subdirectory(exercises/ex3_json_builder)
