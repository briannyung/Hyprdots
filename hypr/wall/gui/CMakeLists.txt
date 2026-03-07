cmake_minimum_required(VERSION 4.2.3)
project(walman_wayland)
find_package(hyprtoolkit REQUIRED)
target_link_libraries(walman_wayland PRIVATE hyprtoolkit::hyprtoolkit)
