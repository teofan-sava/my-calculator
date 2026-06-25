cmake_minimum_required(VERSION 3.28)
project(my-calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(my-calculator
        Calculator.h
        Calculator.cpp
        main.cpp
)

target_link_libraries(my-calculator PRIVATE Qt6::Widgets)