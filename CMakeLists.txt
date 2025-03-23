cmake_minimum_required(VERSION 3.28.3)
project(OnPon)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

add_executable(onpon main.cpp)
target_link_libraries(onpon PRIVATE sfml-graphics sfml-window sfml-system)
