
cmake_minimum_required(VERSION 3.10)
project(BlackRose)



set(SFML_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/Libreries/SFML)

set(CMAKE_CXX_STANDARD 11)



set(SOURCE_FILES source/main.cpp source/Game.cpp source/Characters/Character.cpp source/Characters/Enemy.cpp source/ProceduralMap.cpp source/Characters/PlayerCharacter.cpp source/Objects/Shield.cpp source/World.cpp source/Objects/Weapon.cpp source/Objects/ConsumableObject.cpp source/Objects/MeleeWeapon.cpp source/Objects/Object.cpp source/Objects/RangedWeapon.cpp include/Game.h include/Entity.h include/Characters/Character.h include/Characters/Enemy.h include/ProceduralMap.h include/Inventory.h include/Characters/PlayerCharacter.h include/management/ResourceHolder.h include/management/ResourceIdentifier.h include/Objects/Shield.h include/Objects/Weapon.h include/Objects/ConsumableObject.h include/Objects/MeleeWeapon.h include/Objects/Object.h include/Objects/RangedWeapon.h include/World.h source/Projectile.cpp include/Projectile.h source/Random.cpp include/Random.h source/Entity.cpp )
add_executable(BlackRose  ${SOURCE_FILES} source/Game.cpp include/Game.h)

set(CMAKE_MODULE_PATH ${SFML_ROOT}/sfml_cmake)
find_package(SFML REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(BlackRose ${SFML_LIBRARIES})