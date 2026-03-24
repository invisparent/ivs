cmake_minimum_required(VERSION 4.0)

project(ivs C)

set(CMAKE_C_STANDARD 11)

set(IVS_INCLUDE_LOCAL ./include)

add_library(ivs STATIC)
file(GLOB IVS_SRCS ./src/*.c)
target_sources(ivs PRIVATE ${IVS_SRCS})
target_include_directories(ivs PRIVATE ${IVS_INCLUDE_LOCAL})
target_compile_definitions(ivs PRIVATE $<$<CONFIG:Release,MinSizeRel>:IVS_NDEBUG>)
