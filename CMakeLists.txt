cmake_minimum_required(VERSION 3.12)
project(qt_game_demo)


set(CMAKE_CXX_STANDARD 17)


find_package(Qt5 REQUIRED Widgets)
set(CMAKE_AUTOMOC ON)


add_executable(qt_game_demo main.cpp GamePiece.cpp GamePiece.hpp GameBoard.cpp GameBoard.hpp)

target_link_libraries(qt_game_demo Qt5::Widgets)


