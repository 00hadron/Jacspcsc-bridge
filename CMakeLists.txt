cmake_minimum_required(VERSION 3.24)
project(Jacspcsc C)

set(CMAKE_C_STANDARD 11)

#find_package(Java 1.8)
find_package(JNI)

include_directories(${JAVA_INCLUDE_PATH2} ${JAVA_INCLUDE_PATH})

add_library(Jacspcsc SHARED library.c)
set_target_properties(Jacspcsc PROPERTIES PREFIX "")
target_link_libraries(Jacspcsc ${JAVA_JVM_LIBRARY} winscard)
