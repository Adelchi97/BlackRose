cmake_minimum_required(VERSION 3.8)
project(BlackRose)

set(SFML_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/Libraries/SFML")
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES source/main.cpp source/Game.cpp include/Game.h include/management/ResourceHolder.h
        include/management/ResourceIdentifier.h source/World.cpp include/World.h source/Characters/Character.cpp include/Characters/Character.h include/Inventory.h source/Characters/PlayerCharacter.cpp include/Characters/PlayerCharacter.h source/Objects/Weapon.cpp include/Objects/Weapon.h source/Objects/Shield.cpp include/Objects/Shield.h source/Characters/Enemy.cpp include/Characters/Enemy.h source/Entity.cpp include/Entity.h source/Objects/Object.cpp include/Objects/Object.h source/Objects/ConsumableObject.cpp include/Objects/ConsumableObject.h source/Objects/RangedWeapon.cpp include/Objects/RangedWeapon.h source/Objects/MeleeWeapon.cpp include/Objects/MeleeWeapon.h source/Projectile.cpp include/Projectile.h)
add_executable(BlackRose ${SOURCE_FILES} source/Game.cpp include/Game.h)


set(CMAKE_MODULE_PATH "${SFML_ROOT}/sfml_cmake")
find_package(SFML REQUIRED system window graphics network audio) #cerca i file header
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(BlackRose ${SFML_LIBRARIES})


