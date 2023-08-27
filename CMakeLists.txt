cmake_minimum_required(VERSION 3.26.4)
project(tictactoe)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(tictactoe ${SDL2_LIBRARIES})