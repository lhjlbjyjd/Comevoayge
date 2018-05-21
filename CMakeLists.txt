cmake_minimum_required(VERSION 3.10)
project(Comevoayge)

set(CMAKE_CXX_STANDARD 11)

add_executable(Comevoayge main.cpp Generator.h Boruvka.h Bruteforce.h Generator.cpp Bruteforce.cpp Boruvka.cpp Tester.cpp Tester.h)