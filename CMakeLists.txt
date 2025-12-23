cmake_minimum_required(VERSION 3.31 FATAL_ERROR)
cmake_policy(VERSION 3.31)

# Those options may be set in the preset file
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)

project(coroutines DESCRIPTION "Coroutines" VERSION 0.1.0 LANGUAGES CXX)

if(NOT DEFINED ENV{VCPKG_ROOT})
	message(FATAL_ERROR "VCPKG_ROOT is not defined!")
endif()


add_executable(ex1 src/main.cpp)
target_precompile_headers(ex1 PUBLIC src/main.hpp)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(ex1 PUBLIC nlohmann_json::nlohmann_json)