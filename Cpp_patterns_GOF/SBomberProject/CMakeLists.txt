cmake_minimum_required(VERSION 3.0.0)
project(SBomber VERSION 0.1.0)

set(SOURCE SBomberProject.cpp Bomb.cpp House.cpp Ground.cpp LevelGUI.cpp MyTools.cpp Plane.cpp SBomber.cpp Tank.cpp LogVisitor.cpp)
include_directories(include)

add_executable(SBomber ${SOURCE})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
