cmake_minimum_required(VERSION 3.8)
project(Space_Marine)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Character.cpp Headers/Character.h Command_Repo.cpp Headers/Command_Repo.h)
add_executable(Space_Marine ${SOURCE_FILES})