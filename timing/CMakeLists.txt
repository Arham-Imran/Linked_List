cmake_minimum_required(VERSION 3.5.0)


add_library(timing timing.cpp)
target_include_directories(timing PUBLIC ./)