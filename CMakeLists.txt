cmake_minimum_required(VERSION 3.8)
project(BlackRose)

#cmake_policy(SET CMP0074 OLD)
set(SFML_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/SFML)

set(CMAKE_CXX_STANDARD 11)

message("Adding test subdir")
add_subdirectory(test)


set(SOURCE_FILES source/Game.cpp include/Game.h include/management/ResourceHolder.h source/ProceduralMap.cpp include/ProceduralMap.h
        include/management/ResourceIdentifier.h source/World.cpp include/World.h source/Characters/Character.cpp include/Characters/Character.h
        include/Inventory.h source/Characters/PlayerCharacter.cpp include/Characters/PlayerCharacter.h source/Objects/Weapon.cpp
        include/Objects/Weapon.h source/Objects/Shield.cpp include/Objects/Shield.h source/Characters/Enemy.cpp include/Characters/Enemy.h
        source/Entity.cpp include/Entity.h source/Objects/Object.cpp include/Objects/Object.h source/Objects/ConsumableObject.cpp
        include/Objects/ConsumableObject.h source/Objects/RangedWeapon.cpp include/Objects/RangedWeapon.h source/Objects/MeleeWeapon.cpp
        include/Objects/MeleeWeapon.h source/Projectile.cpp include/Projectile.h include/Random.h source/Random.cpp
        source/Objects/Tile.cpp include/Objects/Tile.h source/Objects/Healpack.cpp include/Objects/Healpack.h source/textDisplay.cpp include/textDisplay.h
        source/Inventory.cpp source/Subject.cpp include/Subject.h
        source/Objects/Tile.cpp include/Objects/Tile.h
        source/Objects/Healpack.cpp include/Objects/Healpack.h source/textDisplay.cpp include/textDisplay.h source/Inventory.cpp
        source/Characters/EnemyFactory.cpp include/Characters/EnemyFactory.h source/Characters/RobotShooter.cpp include/Characters/RobotShooter.h
        source/Characters/RobotFighter.cpp include/Characters/RobotFighter.h source/management/Strategy.cpp include/management/Strategy.h
        source/management/PatrolStrategy.cpp include/management/PatrolStrategy.h source/management/SeekStrategy.cpp include/management/SeekStrategy.h
        source/Achievements/Achievement.cpp include/Achievements/Achievement.h source/Observer.cpp include/Observer.h
        source/Achievements/DemolisherAchievement.cpp include/Achievements/DemolisherAchievement.h source/Achievements/AchievementFactory.cpp include/Achievements/AchievementFactory.h
        source/Achievements/SniperAchievement.cpp include/Achievements/SniperAchievement.h)

add_executable(BlackRose source/main.cpp)


set(CMAKE_MODULE_PATH ${SFML_ROOT}/sfml_cmake)
find_package(SFML REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})

message("Add library")
add_library(core ${SOURCE_FILES})
target_link_libraries(BlackRose core ${SFML_LIBRARIES} )

get_directory_property(output INCLUDE_DIRECTORIES)
message("Include directories:" ${output})
