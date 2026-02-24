cmake_minimum_required(VERSION 3.31)
project(huffman_encoder_decoder)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

add_executable(huffman_encoder_decoder src/main.cpp)
target_link_libraries(huffman_encoder_decoder PRIVATE huffman_encoder_decoder_lib)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/52eb8108c5bdec04579160ae17225d66034bd723.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(huffman_encoder_decoder_test
        test/args_test.cpp)
target_link_libraries(huffman_encoder_decoder_test PRIVATE huffman_encoder_decoder_lib GTest::gtest_main GTest::gmock)

include(GoogleTest)
gtest_discover_tests(huffman_encoder_decoder_test)
