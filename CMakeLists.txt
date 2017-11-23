cmake_minimum_required(VERSION 3.6)
project(Gradius)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake-modules")

find_package(SFML 2 COMPONENTS system window graphics)

set(SOURCE_FILES StopWatch.cpp StopWatch.h Transformation.cpp Transformation.h json.hpp ini_configuration.cc ini_configuration.cc Animation.cpp Animation.h main.cpp Game.cpp Game.h Entity.cpp Entity.h PlayerShip.cpp PlayerShip.h ScrollingEntity.cpp ScrollingEntity.h PlayerBullet.cpp PlayerBullet.h Obstacle.cpp Obstacle.h)

include_directories(${SFML_INCLUDE_DIRS})

add_executable(Gradius ${SOURCE_FILES})

target_link_libraries(Gradius ${SFML_LIBRARIES})