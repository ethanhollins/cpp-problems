cmake_minimum_required(VERSION 3.16.3)

project(Testing)

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} 
    PUBLIC include
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE src
)

target_link_libraries(${PROJECT_NAME})


