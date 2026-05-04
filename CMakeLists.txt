cmake_minimum_required(VERSION 4.1)
project(bugs_life)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(bugs_life
        Bug.cpp
        Bug.h
        Crawler.cpp
        Crawler.h
        Hopper.cpp
        Hopper.h
        main.cpp
        Board.cpp
        Board.h
        Slider.cpp
        Slider.h)
