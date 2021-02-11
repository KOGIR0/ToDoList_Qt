cmake_minimum_required(VERSION 3.0)
project(ToDoList)

# set source files
set(SOURCE_FILES
    source/Task.cpp
    source/TasksList.cpp
    source/InputArea.cpp
    source/MainWindow.cpp
)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Widgets finds its own dependencies.
find_package(Qt5Widgets REQUIRED)

add_executable(ToDoList source/main.cpp ${SOURCE_FILES})
include_directories(include)

qt5_use_modules(ToDoList Widgets)