cmake_minimum_required(VERSION 3.13.4)
project(ParaCL)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

if (NOT DEFINED GRAMMAR)
  set(GRAMMAR "ParaCL.y" CACHE STRING "file with grammar" FORCE)
endif()

set(BISON_FLAGS "-t")

flex_target(scanner
  ParaCL_lexer.l
  ${CMAKE_CURRENT_BINARY_DIR}/ParaCL_lexer.cc
)

bison_target(parser
  ${GRAMMAR}
  ${CMAKE_CURRENT_BINARY_DIR}/parser.cc
  COMPILE_FLAGS "--defines=${CMAKE_CURRENT_BINARY_DIR}/ParaCL.tab.hh")

add_flex_bison_dependency(scanner parser)

add_executable(${PROJECT_NAME} 
  ParaCLdriver.cc  
  ${BISON_parser_OUTPUTS}
  ${FLEX_scanner_OUTPUTS}
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})