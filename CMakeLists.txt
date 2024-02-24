cmake_minimum_required(VERSION 3.13.4)
project(ParaCL)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

if (NOT DEFINED GRAMMAR)
  set(GRAMMAR "compiler.y" CACHE STRING "file with grammar" FORCE)
endif()


flex_target(scanner
  scanner.l
  ${CMAKE_CURRENT_BINARY_DIR}/scanner.cc
)

bison_target(parser
  ${GRAMMAR}
  ${CMAKE_CURRENT_BINARY_DIR}/parser.cc
  COMPILE_FLAGS "--defines=${CMAKE_CURRENT_BINARY_DIR}/compiler.tab.hh")

add_flex_bison_dependency(scanner parser)

set(MYCOMPILE_FLAGS "-g -fsanitize=address")
SET(CMAKE_C_FLAGS    "${CMAKE_C_FLAGS} ${MYCOMPILE_FLAGS}")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${MYCOMPILE_FLAGS}")

add_executable(${PROJECT_NAME} 
  src/driver.cc  
  ${BISON_parser_OUTPUTS}
  ${FLEX_scanner_OUTPUTS}

)
# file(GLOB SRC "src/*")
# file(GLOB INCLUDE "include/*")
# include_directories(src)
# include_directories(include)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
# target_include_directories(${PROJECT_NAME} PRIVATE src)
# target_include_directories(${PROJECT_NAME} PRIVATE include)