cmake_minimum_required(VERSION 3.10)

# Project name and version
project(Financemodel-platformAPI VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the Boost library (if your need it)
find_package(Boost REQUIRED)

# Add Crow Library
include_directories(${CMAKE_SOURCE_DIR}/crow)

# Specify the source files
set(SOURCES
    src/main.cpp
    src/ProfitLossCalculator.cpp
)

# Create the executable
add_executable(ProfitLossAPI ${SOURCES})

find_package(CURL REQUIRED)
if(CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIRS})
    target_link_libraries(ProfitLossAPI ${CURL_LIBRARIES})
endif()