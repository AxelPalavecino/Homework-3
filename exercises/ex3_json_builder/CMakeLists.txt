cmake_minimum_required(VERSION 3.10)
project(ex3_json_builder)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Aplicación principal
add_executable(ex3_json_builder 
    main.cpp
    src/ConstructorDeJSON.cpp
)
