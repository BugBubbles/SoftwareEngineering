# CMakeList.txt : CMake project for CMakeProject7, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("CMakeProject7")
if(MSVC)
add_compile_options("/J")
endif()
# Add source to this project's executable.
add_executable (cbj0 "main.c" "interpret.c" "gui.c")
add_library (cbj1 SHARED "interpret.c" "gui.c")