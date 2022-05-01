cmake_minimum_required(VERSION 3.8.1)
project(example_sort)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O2")
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_MODULE_PATH 
    ${CMAKE_MODULE_PATH} 
    ${CMAKE_CURRENT_SOURCE_DIR}
) # ref: https://keunjun.blog/2018/10/07/cmake-10-%EB%AA%A8%EB%93%88/


find_package(cmake_modules)

set(includeDirs ${includeDirs} ${CMAKE_CURRENT_BINARY_DIR})
set(includeDirs ${includeDirs} include)
set(SRC ${SRC}
src/sorter.cpp
src/timer.cpp
src/heap.cpp)

include_directories( ${includeDirs} )
add_executable (example_sort src/main_sort.cpp ${SRC})
add_executable (example_graph src/main_graph.cpp ${SRC})
add_executable (example_memo src/main_memoization.cpp ${SRC})
add_executable (example_cache src/main_cache.cpp ${SRC})
add_executable (example_heap src/main_heap.cpp ${SRC})
