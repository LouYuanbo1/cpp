cmake_minimum_required(VERSION 3.10)  
project(snake_game)  
  
set(CMAKE_CXX_STANDARD 11)  
  
include_directories(${CMAKE_SOURCE_DIR}/src)  
  
add_executable(snake_game  
    src/main.cpp  
    src/snake.cpp  
    src/food.cpp  
)  
  
target_link_libraries(snake_game -lncurses)
