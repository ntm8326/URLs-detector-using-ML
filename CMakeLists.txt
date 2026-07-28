cmake_minimum_required(VERSION 3.16)
project(BaseModelTest VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)

#add subdir which contains C++ file
add_subdirectory(src_cpp)


enable_testing()
add_subdirectory(tests)