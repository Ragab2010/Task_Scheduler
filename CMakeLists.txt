cmake_minimum_required(VERSION 3.12)
project(TaskSchedulerProject)

set(CMAKE_CXX_STANDARD 17)

# Set the source files and include directories
set(SOURCES
    src/main.cpp
    src/Task.cpp
    src/TaskScheduler.cpp
    #src/TimeManager.cpp
    #src/RandomNumberGenerator.cpp
)

set(INCLUDE_DIRS
    include
)

# Add the executable target
add_executable(TaskSchedulerProject ${SOURCES})

# Specify include directories
target_include_directories(TaskSchedulerProject PRIVATE ${INCLUDE_DIRS})
