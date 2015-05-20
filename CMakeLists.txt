cmake_minimum_required(VERSION 2.6)
project(tiley)

# Set the output directory
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Create an executable with all .cpp files
set(EXECUTABLE_NAME "tiley")
file(GLOB SRC "tiley/*.cpp")
add_executable(${EXECUTABLE_NAME} ${SRC})

# Use C++14
set_property(TARGET tiley PROPERTY CXX_STANDARD_REQUIRED on)
set_property(TARGET tiley PROPERTY CXX_STANDARD 14)

# Include SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
