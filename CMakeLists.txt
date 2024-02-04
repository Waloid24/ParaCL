cmake_minimum_required(VERSION 3.5)
project(ParaCL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

if (NOT DEFINED GRAMMAR)
  set(GRAMMAR "parser.y" CACHE STRING "file with grammar" FORCE)
endif()

# set(CMAKE_CXX_FLAGS_DEBUG "-Wall -O2")
# set(CMAKE_CXX_FLAGS_RELEASE "-O2")

set(PARSER parser/parser.y)
set(LEXER parser/lexer.l)
set(DRIVER parser/driver.cpp)

flex_target(scanner
  ${LEXER}
  ${CMAKE_CURRENT_BINARY_DIR}/lexer.cc
)

bison_target(parser
  ${PARSER}
  ${CMAKE_CURRENT_BINARY_DIR}/parser.cc
  COMPILE_FLAGS "--defines=${CMAKE_CURRENT_BINARY_DIR}/grammar.tab.hh")

add_flex_bison_dependency(scanner parser)

# add_compile_options(${CMAKE_CXX_FLAGS_RELEASE})

add_executable(${PROJECT_NAME} 
  ${DRIVER} 
  ${BISON_parser_OUTPUTS}
  ${FLEX_scanner_OUTPUTS}
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})