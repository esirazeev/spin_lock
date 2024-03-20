cmake_minimum_required(VERSION 3.27.5)

project(spin-lock-lib VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 20)

# create spin lock lib
add_library(spin_lock SHARED spin_lock/spin_lock.cpp)
target_include_directories(spin_lock INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
