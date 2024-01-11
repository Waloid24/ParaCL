cmake_minimum_required(VERSION 3.5)

project(ParaCL LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS_RELEASE "-O2")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ParaCL_SRC main.cpp)

add_compile_options(${CMAKE_CXX_FLAGS_RELEASE})

message("CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")
message("CMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS_RELEASE}")

add_executable(ParaCL ${ParaCL_SRC})

