cmake_minimum_required(VERSION 3.10)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_BUILD_TYPE debug)

project (
    tests
    VERSION 00.00.01
    LANGUAGES CXX
)

list (APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package (GTest REQUIRED)
include_directories (
    ${GTEST_INCLUDE_DIRS}
    ..
    ../hal/CMSIS/Device/ST/STM32F0xx/Include
    ../hal/CMSIS/Include
)
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable (
    tests
    main.cpp
    gpio_test.cpp
)
target_link_libraries (tests ${GTEST_LIBRARIES} pthread)