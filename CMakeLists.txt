cmake_minimum_required(VERSION 3.17)
project(DesignPatterns)

set(CMAKE_CXX_STANDARD 14)

add_executable(DesignPatterns main.cpp AbstractFactory.cpp Singleton.cpp IObserver.cpp)