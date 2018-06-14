cmake_minimum_required(VERSION 3.10)
project(SFMLTest3)

set(SFML_ROOT "C:/Librerie/SFML-2.4.2")

set(CMAKE_MODULE_PATH "C:/Librerie/SFML-2.4.2/cmake/Modules")
find_package(SFML 2 COMPONENTS REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp Game.cpp Game.h)
add_executable(SFMLTest3 ${SOURCE_FILES})

target_link_libraries(SFMLTest3 ${SFML_LIBRARIES} )