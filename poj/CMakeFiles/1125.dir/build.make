# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/li/algorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/li/algorithm

# Include any dependencies generated for this target.
include poj/CMakeFiles/1125.dir/depend.make

# Include the progress variables for this target.
include poj/CMakeFiles/1125.dir/progress.make

# Include the compile flags for this target's objects.
include poj/CMakeFiles/1125.dir/flags.make

poj/CMakeFiles/1125.dir/1125.o: poj/CMakeFiles/1125.dir/flags.make
poj/CMakeFiles/1125.dir/1125.o: poj/1125.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/li/algorithm/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object poj/CMakeFiles/1125.dir/1125.o"
	cd /home/li/algorithm/poj && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/1125.dir/1125.o -c /home/li/algorithm/poj/1125.cpp

poj/CMakeFiles/1125.dir/1125.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1125.dir/1125.i"
	cd /home/li/algorithm/poj && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/li/algorithm/poj/1125.cpp > CMakeFiles/1125.dir/1125.i

poj/CMakeFiles/1125.dir/1125.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1125.dir/1125.s"
	cd /home/li/algorithm/poj && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/li/algorithm/poj/1125.cpp -o CMakeFiles/1125.dir/1125.s

poj/CMakeFiles/1125.dir/1125.o.requires:
.PHONY : poj/CMakeFiles/1125.dir/1125.o.requires

poj/CMakeFiles/1125.dir/1125.o.provides: poj/CMakeFiles/1125.dir/1125.o.requires
	$(MAKE) -f poj/CMakeFiles/1125.dir/build.make poj/CMakeFiles/1125.dir/1125.o.provides.build
.PHONY : poj/CMakeFiles/1125.dir/1125.o.provides

poj/CMakeFiles/1125.dir/1125.o.provides.build: poj/CMakeFiles/1125.dir/1125.o

# Object files for target 1125
1125_OBJECTS = \
"CMakeFiles/1125.dir/1125.o"

# External object files for target 1125
1125_EXTERNAL_OBJECTS =

poj/1125: poj/CMakeFiles/1125.dir/1125.o
poj/1125: poj/CMakeFiles/1125.dir/build.make
poj/1125: poj/CMakeFiles/1125.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable 1125"
	cd /home/li/algorithm/poj && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1125.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
poj/CMakeFiles/1125.dir/build: poj/1125
.PHONY : poj/CMakeFiles/1125.dir/build

poj/CMakeFiles/1125.dir/requires: poj/CMakeFiles/1125.dir/1125.o.requires
.PHONY : poj/CMakeFiles/1125.dir/requires

poj/CMakeFiles/1125.dir/clean:
	cd /home/li/algorithm/poj && $(CMAKE_COMMAND) -P CMakeFiles/1125.dir/cmake_clean.cmake
.PHONY : poj/CMakeFiles/1125.dir/clean

poj/CMakeFiles/1125.dir/depend:
	cd /home/li/algorithm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/li/algorithm /home/li/algorithm/poj /home/li/algorithm /home/li/algorithm/poj /home/li/algorithm/poj/CMakeFiles/1125.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : poj/CMakeFiles/1125.dir/depend

