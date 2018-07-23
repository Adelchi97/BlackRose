cmake_minimum_required(VERSION 3.8)
project(BlackRose)


set(SFML_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/SFML)
set(GTEST_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/test/googletest)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES source/Game.cpp include/Game.h include/management/ResourceHolder.h source/ProceduralMap.cpp include/ProceduralMap.h
        include/management/ResourceIdentifier.h source/World.cpp include/World.h source/Characters/Character.cpp include/Characters/Character.h
        include/Inventory.h source/Characters/PlayerCharacter.cpp include/Characters/PlayerCharacter.h source/Objects/Weapon.cpp
        include/Objects/Weapon.h source/Objects/Shield.cpp include/Objects/Shield.h source/Characters/Enemy.cpp include/Characters/Enemy.h
        source/Entity.cpp include/Entity.h source/Objects/Object.cpp include/Objects/Object.h source/Objects/ConsumableObject.cpp
        include/Objects/ConsumableObject.h source/Objects/RangedWeapon.cpp include/Objects/RangedWeapon.h source/Objects/MeleeWeapon.cpp
        include/Objects/MeleeWeapon.h source/Projectile.cpp include/Projectile.h include/Random.h source/Random.cpp test/TestPlayerCharacter.h
        test/RunAllTests.cpp)
add_executable(BlackRose ${SOURCE_FILES} source/main.cpp source/Wall.cpp include/Wall.h)


set(CMAKE_MODULE_PATH ${SFML_ROOT}/sfml_cmake)
find_package(SFML REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})

add_library(core ${SOURCE_FILES})
target_link_libraries(BlackRose ${SFML_LIBRARIES} core )

#target_link_libraries(BlackRose ${SOURCE_LIBRARIES})


