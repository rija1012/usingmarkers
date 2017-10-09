cmake_minimum_required(VERSION 2.8.3)
project(using_markers)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  visualization_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES using_markers
#  CATKIN_DEPENDS roscpp visualization_msgs
#  DEPENDS system_lib
)

# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(basic_shapes src/basic_shapes.cpp)
add_executable(basic_shapes2 src/basic_shapes2.cpp)
add_executable(basic_shapes3 src/basic_shapes3.cpp)
target_link_libraries(basic_shapes ${catkin_LIBRARIES})
target_link_libraries(basic_shapes2 ${catkin_LIBRARIES})
target_link_libraries(basic_shapes3 ${catkin_LIBRARIES})
