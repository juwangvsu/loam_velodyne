cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(voxel_grid)

find_package(PCL 1.2 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (voxel_grid ds.cpp)
target_link_libraries (voxel_grid ${PCL_LIBRARIES})

add_executable (voxel_grid2 ds_2.cpp)
target_link_libraries (voxel_grid2 ${PCL_LIBRARIES})
