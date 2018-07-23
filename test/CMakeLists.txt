cmake_minimum_required(VERSION 3.10)

add_subdirectory(lib/googletest)
set(gtest_SOURCE_DIR lib/googletest/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../include)
set(SOURCE_TEST_FILES RunAllTests.cpp)

get_directory_property(output INCLUDE_DIRECTORIES)
message("Included directories test:" ${output})

add_executable(RunAllTests ${SOURCE_TEST_FILES})
target_link_libraries(RunAllTests gtest gtest_main core)
