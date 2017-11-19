cmake_minimum_required(VERSION 3.7)
project(Gradius)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake-modules")

find_package(SFML 2 COMPONENTS system window graphics)

set(SOURCE_FILES main.cpp StopWatch.cpp StopWatch.h Entity.cpp Entity.h EntityResource.cpp EntityResource.h Game.cpp Game.h EntityController.cpp EntityController.h EntityView.cpp EntityView.h Transformation.cpp Transformation.h PlayerShip.cpp PlayerShip.h PlayerBullet.cpp PlayerBullet.h ScrollingEntity.cpp ScrollingEntity.h EnemyShip.cpp EnemyShip.h BorderObstacle.cpp BorderObstacle.h Obstacle.cpp Obstacle.h json.hpp ini_configuration.cc ini_configuration.cc Animation.cpp Animation.h)

include_directories(${SFML_INCLUDE_DIRS})

add_executable(Gradius ${SOURCE_FILES})

target_link_libraries(Gradius ${SFML_LIBRARIES})