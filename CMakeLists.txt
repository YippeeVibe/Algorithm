cmake_minimum_required(VERSION 3.5)
#set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR} D:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake
#CACHE STRING "Vcpkg toolchain file")
project(Algorithm_DataStruct LANGUAGES CXX)

# 使用ccache编译缓存，加快编译速度
find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
    message("####ccache has loaded!")
else()
    message("####ccache has unloaded!")
endif()
#设置使用clang(kei'lang)编译器
#set(CMAKE_CXX_COMPILER clang++-10)
# 打印当前的操作系统 和C++ 编译器
message("####current system: ${CMAKE_SYSTEM_NAME}")
message("####current cxx_compiler ${CMAKE_CXX_COMPILER}")

# 增加预编译定义 LINUX
if(UNIX)
    add_definitions(-DUNIX)
elseif(WIN32)
    add_definitions(-DWIN32)
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(HANOI
     Hanoi/hanoi.hpp
 )
set(SORT
    Sort/sort.hpp
    )
set(ConvexHull
    ConvexHull/ConvexHull.hpp
    )
add_executable(${PROJECT_NAME}
  main.cpp
  ${HANOI}
  ${SORT}
  ${ConvexHull}
)

