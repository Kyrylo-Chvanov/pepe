cmake_minimum_required(VERSION 3.31)
project(pepe)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS        OFF)

add_executable(${PROJECT_NAME}
  src/main.cc
  src/pepe.cc
  src/pepe.h
  src/app.h
  src/app.cc
  src/window.h
  src/window.cc
  src/animation.cc
  src/animation.h
)

find_package(raylib)
find_package(SFML COMPONENTS Window)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Window)