# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/begechhaciyew/CLionProjects/hazirlik

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/begechhaciyew/CLionProjects/hazirlik/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hazirlik.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/hazirlik.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hazirlik.dir/flags.make

CMakeFiles/hazirlik.dir/main.cpp.o: CMakeFiles/hazirlik.dir/flags.make
CMakeFiles/hazirlik.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/begechhaciyew/CLionProjects/hazirlik/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hazirlik.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hazirlik.dir/main.cpp.o -c /Users/begechhaciyew/CLionProjects/hazirlik/main.cpp

CMakeFiles/hazirlik.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hazirlik.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/begechhaciyew/CLionProjects/hazirlik/main.cpp > CMakeFiles/hazirlik.dir/main.cpp.i

CMakeFiles/hazirlik.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hazirlik.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/begechhaciyew/CLionProjects/hazirlik/main.cpp -o CMakeFiles/hazirlik.dir/main.cpp.s

# Object files for target hazirlik
hazirlik_OBJECTS = \
"CMakeFiles/hazirlik.dir/main.cpp.o"

# External object files for target hazirlik
hazirlik_EXTERNAL_OBJECTS =

hazirlik: CMakeFiles/hazirlik.dir/main.cpp.o
hazirlik: CMakeFiles/hazirlik.dir/build.make
hazirlik: CMakeFiles/hazirlik.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/begechhaciyew/CLionProjects/hazirlik/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hazirlik"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hazirlik.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hazirlik.dir/build: hazirlik
.PHONY : CMakeFiles/hazirlik.dir/build

CMakeFiles/hazirlik.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hazirlik.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hazirlik.dir/clean

CMakeFiles/hazirlik.dir/depend:
	cd /Users/begechhaciyew/CLionProjects/hazirlik/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/begechhaciyew/CLionProjects/hazirlik /Users/begechhaciyew/CLionProjects/hazirlik /Users/begechhaciyew/CLionProjects/hazirlik/cmake-build-debug /Users/begechhaciyew/CLionProjects/hazirlik/cmake-build-debug /Users/begechhaciyew/CLionProjects/hazirlik/cmake-build-debug/CMakeFiles/hazirlik.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hazirlik.dir/depend
