cmake_minimum_required(VERSION 3.0)
project(Gradius)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake-modules")

find_package(SFML 2 COMPONENTS system window graphics)

set(SOURCE_FILES src/StopWatch.cpp src/StopWatch.h src/Transformation.cpp src/Transformation.h src/json.hpp src/ini_configuration.cc src/ini_configuration.cc src/Animation.cpp src/Animation.h src/main.cpp src/Game.cpp src/Game.h src/Singleton.h src/Exception.cpp src/Exception.h src/controllers/Entity.cpp src/controllers/Entity.h src/models/Entity.cpp src/models/Entity.h src/views/Entity.cpp src/views/Entity.h src/resources/Entity.cpp src/resources/Entity.h src/controllers/PlayerBullet.cpp src/controllers/PlayerBullet.h src/models/PlayerBullet.cpp src/models/PlayerBullet.h src/resources/PlayerBullet.cpp src/resources/PlayerBullet.h src/controllers/PlayerShip.cpp src/controllers/PlayerShip.h src/models/PlayerShip.cpp src/models/PlayerShip.h src/resources/PlayerShip.cpp src/resources/PlayerShip.h src/views/Ship.cpp src/views/Ship.h src/controllers/ScrollingEntity.cpp src/controllers/ScrollingEntity.h src/models/ScrollingEntity.cpp src/models/ScrollingEntity.h src/models/EnemyShip.cpp src/models/EnemyShip.h src/resources/EnemyShip.cpp src/resources/EnemyShip.h src/models/Obstacle.cpp src/models/Obstacle.h src/resources/Obstacle.cpp src/resources/Obstacle.h src/models/BorderObstacle.cpp src/models/BorderObstacle.h src/resources/BorderObstacle.cpp src/resources/BorderObstacle.h src/controllers/EnemyShip.cpp src/controllers/EnemyShip.h src/models/EnemyBullet.cpp src/models/EnemyBullet.h src/controllers/EnemyBullet.cpp src/controllers/EnemyBullet.h src/resources/EnemyBullet.h src/resources/EnemyBullet.cpp src/models/Ship.cpp src/models/Ship.h src/controllers/Ship.cpp src/controllers/Ship.h src/resources/Ship.cpp src/resources/Ship.h src/controllers/EnemyShipAI1.cpp src/controllers/EnemyShipAI1.h src/controllers/Controller.cpp src/controllers/Controller.h src/models/Model.cpp src/models/Model.h src/views/View.cpp src/views/View.h src/Level.cpp src/Level.h src/controllers/EnemyShipAI2.cpp src/controllers/EnemyShipAI2.h src/Hitbox.cpp src/Hitbox.h)

include_directories(${SFML_INCLUDE_DIRS})

add_executable(Gradius ${SOURCE_FILES})

target_link_libraries(Gradius ${SFML_LIBRARIES})
