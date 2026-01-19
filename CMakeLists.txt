cmake_minimum_required(VERSION 3.10.0)
project(TicTacBot VERSION 0.1.0 LANGUAGES C CXX)

add_executable(TicTacBot state.cpp move.cpp bot.cpp board.cpp game.cpp main.cpp)

include(CTest)
enable_testing()

