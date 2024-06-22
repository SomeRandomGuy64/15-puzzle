# CMakeList.txt : CMake project for Chapter 21 Project, include source and define
# project specific logic here.
#

# Set warning level for MSVC
if (MSVC)
	add_compile_options(/W4 /WX)
endif()

# Add source to this project's executable.
add_executable (CMakeTarget "main.cpp"  "includes/random.h" "includes/board.h" "includes/tile.h" "includes/point.h" "includes/command.h" "includes/userInput.h" "board.cpp" "command.cpp" "point.cpp" "tile.cpp")

set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS_OFF)

# TODO: Add tests and install targets if needed.

