cmake_minimum_required(VERSION 3.31)
project(huffman_encoder_decoder)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)
include_directories(src)

add_executable(huffman_encoder_decoder
        src/main.cpp)
