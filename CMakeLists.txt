cmake_minimum_required(VERSION 3.8)
project(Space_Marine)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES Source/main.cpp Source/character.cpp Headers/character.h Source/command_repo.cpp Headers/command_repo.h Headers/economy_controller.h Source/economy_controller.cpp Source/input_check.cpp Headers/input_check.h Source/console.cpp Headers/console.h)
add_executable(Space_Marine ${SOURCE_FILES})