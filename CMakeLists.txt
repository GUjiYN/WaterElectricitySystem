include_directories("D:\\MySQL\\MySQL\\include")
link_directories("D:\\MySQL\\MySQL\\lib")
link_libraries(libmysql)

add_executable(WaterElectricitySystem main.cpp)
cmake_minimum_required(VERSION 3.10)
project(WaterElectricitySystem)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)

# 确保链接到正确的库
target_link_libraries(WaterElectricitySystem libmysql)
