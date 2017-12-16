cmake_minimum_required(VERSION 3.8)
project(Space_Marine)

find_package(Boost)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES Source/main.cpp Source/Character.cpp Headers/Character.h Source/Command_Repo.cpp Headers/Command_Repo.h)
add_executable(Space_Marine ${SOURCE_FILES})