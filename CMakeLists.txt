cmake_minimum_required(VERSION 3.20)
project(ycp CXX)

set(CXX_STANDARD 11)
add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)