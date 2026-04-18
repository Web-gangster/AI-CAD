cmake_minimum_required(VERSION 3.16)
project(qt_mini_blender)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
find_package(Qt5 REQUIRED COMPONENTS Widgets OpenGL Gui OpenGLExtensions)
add_executable(qt_mini_blender 
    main.cpp
    MainWindow.h
    MainWindow.cpp
    ViewportWidget.h
    ViewportWidget.cpp
)
target_link_libraries(qt_mini_blender Qt5::Widgets Qt5::OpenGL Qt5::Gui Qt5::OpenGLExtensions)