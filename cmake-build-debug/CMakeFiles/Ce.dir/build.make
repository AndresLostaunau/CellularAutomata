# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\alost\OneDrive\Escritorio\CellularAutomata

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\alost\OneDrive\Escritorio\CellularAutomata\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Ce.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Ce.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ce.dir/flags.make

CMakeFiles/Ce.dir/GameOfLife.cpp.obj: CMakeFiles/Ce.dir/flags.make
CMakeFiles/Ce.dir/GameOfLife.cpp.obj: ../GameOfLife.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alost\OneDrive\Escritorio\CellularAutomata\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ce.dir/GameOfLife.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Ce.dir\GameOfLife.cpp.obj -c C:\Users\alost\OneDrive\Escritorio\CellularAutomata\GameOfLife.cpp

CMakeFiles/Ce.dir/GameOfLife.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ce.dir/GameOfLife.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\alost\OneDrive\Escritorio\CellularAutomata\GameOfLife.cpp > CMakeFiles\Ce.dir\GameOfLife.cpp.i

CMakeFiles/Ce.dir/GameOfLife.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ce.dir/GameOfLife.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\alost\OneDrive\Escritorio\CellularAutomata\GameOfLife.cpp -o CMakeFiles\Ce.dir\GameOfLife.cpp.s

CMakeFiles/Ce.dir/main.cpp.obj: CMakeFiles/Ce.dir/flags.make
CMakeFiles/Ce.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alost\OneDrive\Escritorio\CellularAutomata\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Ce.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Ce.dir\main.cpp.obj -c C:\Users\alost\OneDrive\Escritorio\CellularAutomata\main.cpp

CMakeFiles/Ce.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ce.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\alost\OneDrive\Escritorio\CellularAutomata\main.cpp > CMakeFiles\Ce.dir\main.cpp.i

CMakeFiles/Ce.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ce.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\alost\OneDrive\Escritorio\CellularAutomata\main.cpp -o CMakeFiles\Ce.dir\main.cpp.s

# Object files for target Ce
Ce_OBJECTS = \
"CMakeFiles/Ce.dir/GameOfLife.cpp.obj" \
"CMakeFiles/Ce.dir/main.cpp.obj"

# External object files for target Ce
Ce_EXTERNAL_OBJECTS =

Ce.exe: CMakeFiles/Ce.dir/GameOfLife.cpp.obj
Ce.exe: CMakeFiles/Ce.dir/main.cpp.obj
Ce.exe: CMakeFiles/Ce.dir/build.make
Ce.exe: CMakeFiles/Ce.dir/linklibs.rsp
Ce.exe: CMakeFiles/Ce.dir/objects1.rsp
Ce.exe: CMakeFiles/Ce.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\alost\OneDrive\Escritorio\CellularAutomata\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Ce.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Ce.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ce.dir/build: Ce.exe

.PHONY : CMakeFiles/Ce.dir/build

CMakeFiles/Ce.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Ce.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Ce.dir/clean

CMakeFiles/Ce.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\alost\OneDrive\Escritorio\CellularAutomata C:\Users\alost\OneDrive\Escritorio\CellularAutomata C:\Users\alost\OneDrive\Escritorio\CellularAutomata\cmake-build-debug C:\Users\alost\OneDrive\Escritorio\CellularAutomata\cmake-build-debug C:\Users\alost\OneDrive\Escritorio\CellularAutomata\cmake-build-debug\CMakeFiles\Ce.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ce.dir/depend

