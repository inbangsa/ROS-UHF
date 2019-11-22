cmake_minimum_required(VERSION 3.4)
project(ROS-UHF_FrameWork CXX)


#set(CMAKE_C_COMPILER "/usr/bin/cc")
#set(CMAKE_CXX_COMPILER "/usr/bin/g++")


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#### FOR building the lib. ###########################

#make a list of all header files
file(GLOB header_files ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h $CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

#make a list of all the source files 
file(GLOB src_files ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)


#add the library
add_library(driver_lib ${header_files} ${src_files})

target_include_directories(driver_lib PUBLIC 
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> 	
$<INSTALL_INTERFACE:${_include}>)

add_executable(sample sample.cpp)

target_link_libraries(sample driver_lib)

INSTALL(TARGETS sample  DESTINATION bin)


#### FOR BUILDING Package for ROS. ###########################

#Find catkin and all the required packages.
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg message_generation)

## Declare ROS messages and services.
add_service_files(FILES ConfigDevice.srv GetData.srv)


## Declare a catkin package.
catkin_package( CATKIN_DEPENDS message_runtime)

## Build service and clients and/or subscriber and publisher.
include_directories(include ${catkin_INCLUDE_DIRS})
include_directories(${header_files})

## Executable for Service and Client.
add_executable(node_server node/server.cpp ${src_files})
target_link_libraries(node_server ${catkin_LIBRARIES})
add_dependencies(node_server ROS-UHF_gencpp)

add_executable(node_client node/client.cpp )
target_link_libraries(node_client ${catkin_LIBRARIES})
add_dependencies(node_client ROS-UHF_gencpp)

install(TARGETS node_server node_client
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)







