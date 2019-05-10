cmake_minimum_required(VERSION 2.8)

project(PVRTexLibWrapper)

file(GLOB SOURCES src/*.cpp)

include_directories(/opt/Imagination/PowerVR_Graphics/PowerVR_Tools/PVRTexTool/Library/Include)
link_directories(/opt/Imagination/PowerVR_Graphics/PowerVR_Tools/PVRTexTool/Library/Linux_x86_64)

add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_link_libraries(${PROJECT_NAME} PVRTexLib)
