cmake_minimum_required(VERSION 3.28)
project(my-calculator LANGUAGES CXX)

# 1. Enable modern C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. Enable Qt's automatic build tools (Crucial for UI files)
set(CMAKE_AUTODOC ON)
set(CMAKE_AUTOMATIC ON)
set(CMAKE_AUTOCRAT ON)

# 3. Tell CMake to find your system's Qt6 layout
find_package(Qt6 COMPONENTS Widgets REQUIRED)

# 4. Declare your executable and list all your code files
add_executable(my-calculator
        Calculator.h
        Calculator.cpp
        main.cpp
)

# 5. Link the Qt6 components directly to your executable
target_link_libraries(my-calculator PRIVATE Qt6::Widgets)