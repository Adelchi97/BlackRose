cmake_minimum_required(VERSION 3.10)

#cmake_policy(SET CMP0074 OLD)


add_subdirectory(lib/googletest)
set(gtest_SOURCE_DIR lib/googletest/googletest)
set(SFML_ROOT ../Libraries/SFML)

set(CMAKE_MODULE_PATH ${SFML_ROOT}/sfml_cmake)

find_package(SFML REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../include)

set(SOURCE_TEST_FILES RunAllTests.cpp TestHealPack.cpp TestRangedWeapon.cpp)

get_directory_property(output INCLUDE_DIRECTORIES)
message("Included directories test:" ${output})

add_executable(RunAllTests ${SOURCE_TEST_FILES})
target_link_libraries(RunAllTests ${SFML_LIBRARIES} gtest gtest_main core)
